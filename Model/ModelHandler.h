//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MODELHANDLER_H
#define GOTIKZ_MODELHANDLER_H

#include "Controller/ModifierState.h"
#include "Drawable/DrawableHandler.h"
#include "Model/MousePointerTypeEnum.h"

#include <QMouseEvent>
#include <memory>

namespace Controller {
    class ModifierState;
    class ActionHandler;
} // namespace Controller

namespace Model {
    class ModelHandler {
      public:
        explicit ModelHandler(Controller::ActionHandler* actionHandler);

        const DrawableHandler& drawableHandler() const;
        DrawableHandler&       drawableHandler();

        void    mouseLeftClick(const QPointF& mousePosition);
        void    mouseRightClick(const QPointF& mousePosition, const Controller::ModifierState& modifierState);
        void    mouseMiddleClick(const QPointF& mousePosition);
        void    selectEvent(const QPointF& mousePosition, bool shouldClearSelected);
        void    mouseMoveEvent(const QPointF& mousePosition);
        void    setPen(const QPen& pen);
        void    setMousePointerType(MOUSE_POINTER_TYPE newType);
        QPointF mousePointInWorldCoordinates(const QPointF& mousePoint) const;

      private:
        std::unique_ptr<DrawableHandler> m_drawableHandler;
        Controller::ActionHandler*       m_actionHandler;
        QPen                             m_drawPen          = QPen(Qt::black, 3);
        MOUSE_POINTER_TYPE               m_mousePointerType = MOUSE_POINTER_TYPE::LINE;
    };
} // namespace Model

#endif // GOTIKZ_MODELHANDLER_H
