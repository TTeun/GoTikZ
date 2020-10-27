//
// Created by pc on 27-10-20.
//

#include "Model.h"

#include "../Widgets/DrawWidget.h"
#include "Actions/ActionHandler.h"

#include <Actions/AddPrimitiveAction.h>
#include <Drawable/Point.h>
#include <Drawable/StreamDrawableFactory.h>
#include <QDebug>

Model::Model(ActionHandler* actionHandler) : m_actionHandler(actionHandler) {
    assert(m_actionHandler);
}

const DrawableHandler& Model::drawableHandler() const {
    return m_drawableHandler;
}

DrawableHandler& Model::drawableHandler() {
    return m_drawableHandler;
}

void Model::mousePressEvent(QMouseEvent* event) {
    if (m_mousePointerType == MOUSE_POINTER_TYPE::SELECT) {
        auto* selected = m_drawableHandler.selectClosest(event->localPos());
        if (selected != nullptr) {
            m_actionHandler->setEditWidget(selected->toWidget(m_actionHandler));
        }
        return;
    }

    QPointF m_mousePoint = m_drawableHandler.snap(event->localPos());
    if (not m_drawableHandler.isStreaming()) {
        switch (m_mousePointerType) {
            case MOUSE_POINTER_TYPE::POINT:
                m_drawableHandler.addDrawable(new Point(m_mousePoint, m_drawPen));
                m_actionHandler->addAction(new AddPrimitiveAction(m_drawableHandler.drawables().back()->index()), true);
                break;
            default:
                m_drawableHandler.addStreamDrawable(
                    StreamDrawableFactory::make(m_mousePoint, m_mousePointerType, m_drawPen));
                break;
        }
    } else {
        if (m_drawableHandler.addPointToStreamDrawable(m_mousePoint, event->button() == Qt::RightButton)) {
            m_actionHandler->addAction(new AddPrimitiveAction(m_drawableHandler.drawables().back()->index()), true);
        }
    }
}

void Model::mouseMoveEvent(QMouseEvent* event) {
    QPointF m_mousePoint = m_drawableHandler.snap(event->localPos());
    if (m_drawableHandler.isStreaming()) {
        m_drawableHandler.stream(m_mousePoint);
    } else if (m_mousePointerType == MOUSE_POINTER_TYPE::SELECT) {
        m_drawableHandler.highlightClosest(event->localPos());
    }
}

void Model::setPen(const QPen& pen) {
    m_drawPen = pen;
}

void Model::setMousePointerType(MOUSE_POINTER_TYPE newType) {
    if (m_drawableHandler.isStreaming()) {
        m_drawableHandler.stopStreaming();
    }

    m_mousePointerType = newType;
}
