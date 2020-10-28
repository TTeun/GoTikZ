//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MODEL_H
#define GOTIKZ_MODEL_H

#include "../Controller/Actions/ActionHandler.h"
#include "Drawable/DrawableHandler.h"
#include "Model/MousePointerTypeEnum.h"

#include <QMouseEvent>

namespace Controller {
class ActionHandler;
}

class Model {
  public:
    explicit Model(Controller::ActionHandler* actionHandler);

    const DrawableHandler& drawableHandler() const;
    DrawableHandler&       drawableHandler();
    void                   mousePressEvent(QMouseEvent* event);
    void                   mouseSelectEvent(QMouseEvent* event);
    void                   mouseCreateEvent(const QPointF& snappedPoint);
    void                   mouseMoveEvent(QMouseEvent* event);
    void                   setPen(const QPen& pen);
    void                   setMousePointerType(MOUSE_POINTER_TYPE newType);
    QPointF                mousePointInWorldCoordinates(const QPointF& mousePoint) const;

  private:
    DrawableHandler            m_drawableHandler;
    Controller::ActionHandler* m_actionHandler;
    QPen                       m_drawPen          = QPen(Qt::black, 3);
    MOUSE_POINTER_TYPE         m_mousePointerType = MOUSE_POINTER_TYPE::LINE;
};

#endif // GOTIKZ_MODEL_H
