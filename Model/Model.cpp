//
// Created by pc on 27-10-20.
//

#include "Model.h"

#include "Controller/Actions/HidePrimitiveAction.h"
#include "Controller/Actions/ShowPrimitiveAction.h"
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
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->stream(
            m_drawableHandler->snap(m_controller->coordinateConverter().screenToWorld(mousePosition),
                                    m_controller->coordinateConverter().screenToWorldDistance(30)));
    } else {
        m_drawableHandler->highlightClosest(m_controller->coordinateConverter().screenToWorld(mousePosition));
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

void model::Model::setPoint(const QPointF& pointPosition, const controller::ModifierState& modifierState) {
    m_drawableHandler->clearSelectedAndHighlighted();
    if (not m_drawableHandler->isStreaming()) {
        switch (m_mousePointerType) {
            case PRIMITIVE_TYPE::POINT:
                m_drawableHandler->addDrawable(new Point(pointPosition, m_drawPen));
                m_controller->addAction(
                    new controller::ShowPrimitiveAction(m_drawableHandler->drawables().back()->index()), true);
                break;
            default:
                m_drawableHandler->addStreamDrawable(
                    StreamDrawableFactory::make(pointPosition, m_mousePointerType, m_drawPen));
                break;
        }
    } else {
        if (m_drawableHandler->addPointToStreamDrawable(pointPosition, false)) {
            m_controller->addAction(new controller::ShowPrimitiveAction(m_drawableHandler->drawables().back()->index()),
                                    true);
        }
    }
}

Drawable* model::Model::selectNew(const QPointF& mousePosition) {
    return m_drawableHandler->selectNew(m_controller->coordinateConverter().screenToWorld(mousePosition));
}

Drawable* model::Model::addToSelected(const QPointF& mousePosition) {
    return m_drawableHandler->addToSelected(m_controller->coordinateConverter().screenToWorld(mousePosition));
}

void model::Model::deleteSelected() {
    if (not m_drawableHandler->selectedDrawables().empty()) {
        m_controller->addAction(new controller::HidePrimitiveAction(drawableHandler().indicesOfSelectedDrawable()),
                                false);
    }
}
