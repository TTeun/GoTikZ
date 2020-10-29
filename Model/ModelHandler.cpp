//
// Created by pc on 27-10-20.
//

#include "ModelHandler.h"

#include "Controller/Actions/ActionHandler.h"
#include "Controller/Actions/AddPrimitiveAction.h"
#include "Drawable/Point.h"
#include "Drawable/StreamDrawableFactory.h"
#include "Model/MousePointerTypeEnum.h"
#include "View/Widgets/DrawWidget.h"

#include <QDebug>

Model::ModelHandler::ModelHandler(Controller::ActionHandler* actionHandler)
    : m_drawableHandler(new DrawableHandler()), m_actionHandler(actionHandler) {
    assert(m_actionHandler);
}

const DrawableHandler& Model::ModelHandler::drawableHandler() const {
    return *m_drawableHandler;
}

DrawableHandler& Model::ModelHandler::drawableHandler() {
    return *m_drawableHandler;
}

void Model::ModelHandler::selectEvent(const QPointF& mousePosition, bool shouldClearSelected) {
    auto* selected = m_drawableHandler->selectClosest(mousePointInWorldCoordinates(mousePosition), false);
    if (selected != nullptr) {
        m_actionHandler->setEditWidget(selected->toWidget(m_actionHandler));
    }
}

void Model::ModelHandler::mouseMoveEvent(const QPointF& mousePosition) {
    const auto snappedMousePoint = m_drawableHandler->snap(mousePointInWorldCoordinates(mousePosition));
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->stream(snappedMousePoint);
    } else if (m_mousePointerType == Model::MOUSE_POINTER_TYPE::SELECT) {
        m_drawableHandler->highlightClosest(mousePointInWorldCoordinates(mousePosition));
    }
}

void Model::ModelHandler::setPen(const QPen& pen) {
    m_drawPen = pen;
}

void Model::ModelHandler::setMousePointerType(Model::MOUSE_POINTER_TYPE newType) {
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->stopStreaming();
    }

    m_mousePointerType = newType;
}

QPointF Model::ModelHandler::mousePointInWorldCoordinates(const QPointF& mousePoint) const {
    return m_actionHandler->drawWidget()->transform().invertTransform(mousePoint);
}

void Model::ModelHandler::mouseLeftClick(const QPointF& mousePosition) {
    const auto snappedPoint = m_drawableHandler->snap(mousePointInWorldCoordinates(mousePosition));
    if (m_mousePointerType == Model::MOUSE_POINTER_TYPE::SELECT) {
        selectEvent(mousePosition, false);
    } else {
        m_drawableHandler->clearSelectedAndHighlighted();
        if (not m_drawableHandler->isStreaming()) {
            switch (m_mousePointerType) {
                case Model::MOUSE_POINTER_TYPE::POINT:
                    m_drawableHandler->addDrawable(new Point(snappedPoint, m_drawPen));
                    m_actionHandler->addAction(
                        new Controller::AddPrimitiveAction(m_drawableHandler->drawables().back()->index()), true);
                    break;
                default:
                    m_drawableHandler->addStreamDrawable(
                        StreamDrawableFactory::make(snappedPoint, m_mousePointerType, m_drawPen));
                    break;
            }
        } else {
            if (m_drawableHandler->addPointToStreamDrawable(snappedPoint, false)) {
                m_actionHandler->addAction(
                    new Controller::AddPrimitiveAction(m_drawableHandler->drawables().back()->index()), true);
            }
        }
    }
}

void Model::ModelHandler::mouseRightClick(const QPointF&                   mousePosition,
                                          const Controller::ModifierState& modifierState) {
    const auto snappedPoint = m_drawableHandler->snap(mousePointInWorldCoordinates(mousePosition));
    if (m_drawableHandler->isStreaming()) {
        m_drawableHandler->addPointToStreamDrawable(snappedPoint, true);
        m_actionHandler->addAction(new Controller::AddPrimitiveAction(m_drawableHandler->drawables().back()->index()),
                                   true);
    } else {
        selectEvent(mousePosition, not modifierState.shiftPressed());
    }
}

void Model::ModelHandler::mouseMiddleClick(const QPointF& mousePosition) {
}
