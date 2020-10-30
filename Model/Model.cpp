//
// Created by pc on 27-10-20.
//

#include "Model.h"

#include "Controller/Actions/AddPrimitiveAction.h"
#include "Controller/Controller.h"
#include "Drawable/Point.h"
#include "Drawable/StreamDrawableFactory.h"
#include "Model/PrimitiveTypeEnum.h"
#include "View/Widgets/DrawWidget.h"

#include <QDebug>

model::Model::Model(controller::Controller* controller)
    : m_drawableHandler(new DrawableHandler()), m_controller(controller) {
    assert(m_controller);
}

const DrawableHandler& model::Model::drawableHandler() const {
    return *m_drawableHandler;
}

DrawableHandler& model::Model::drawableHandler() {
    return *m_drawableHandler;
}

void model::Model::mouseMoveEvent(const QPointF& mousePosition) {
    const auto snappedMousePoint = m_drawableHandler->snap(mousePointInWorldCoordinates(mousePosition));
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->stream(snappedMousePoint);
    } else {
        m_drawableHandler->highlightClosest(mousePointInWorldCoordinates(mousePosition));
    }
}

void model::Model::setPen(const QPen& pen) {
    m_drawPen = pen;
}

void model::Model::setMousePointerType(PRIMITIVE_TYPE newType) {
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->stopStreaming();
    }

    m_mousePointerType = newType;
}

QPointF model::Model::mousePointInWorldCoordinates(const QPointF& mousePoint) const {
    return m_controller->drawWidget()->transform().invertTransform(mousePoint);
}

void model::Model::setPoint(const QPointF& mousePosition, const controller::ModifierState& modifierState) {
    const auto snappedPoint = m_drawableHandler->snap(mousePointInWorldCoordinates(mousePosition));

    m_drawableHandler->clearSelectedAndHighlighted();
    if (not m_drawableHandler->isStreaming()) {
        switch (m_mousePointerType) {
            case PRIMITIVE_TYPE::POINT:
                m_drawableHandler->addDrawable(new Point(snappedPoint, m_drawPen));
                m_controller->addAction(
                    new controller::AddPrimitiveAction(m_drawableHandler->drawables().back()->index()), true);
                break;
            default:
                m_drawableHandler->addStreamDrawable(
                    StreamDrawableFactory::make(snappedPoint, m_mousePointerType, m_drawPen));
                break;
        }
    } else {
        if (m_drawableHandler->addPointToStreamDrawable(snappedPoint, false)) {
            m_controller->addAction(
                new controller::AddPrimitiveAction(m_drawableHandler->drawables().back()->index()), true);
        }
    }
}

Drawable* model::Model::selectNew(const QPointF& mousePosition) {
    return m_drawableHandler->selectNew(mousePointInWorldCoordinates(mousePosition));
}

Drawable* model::Model::addToSelected(const QPointF& mousePosition) {
    return m_drawableHandler->addToSelected(mousePointInWorldCoordinates(mousePosition));
}
