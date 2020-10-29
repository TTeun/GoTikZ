//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MODEL_H
#define GOTIKZ_MODEL_H

#include "Controller/ModifierState.h"
#include "Drawable/DrawableHandler.h"
#include "Model/MousePointerTypeEnum.h"

#include <QMouseEvent>
#include <memory>

namespace controller {
    class ModifierState;
    class Controller;
} // namespace controller

namespace model {
    class Model {
      public:
        explicit Model(controller::Controller* actionHandler);

        const DrawableHandler& drawableHandler() const;
        DrawableHandler&       drawableHandler();

        void setPoint(const QPointF& mousePosition, const controller::ModifierState& modifierState);
        void selectNew(const QPointF& mousePosition);
        void addToSelected(const QPointF& mousePosition);

        void    mouseMoveEvent(const QPointF& mousePosition);
        void    setPen(const QPen& pen);
        void    setMousePointerType(MOUSE_POINTER_TYPE newType);
        QPointF mousePointInWorldCoordinates(const QPointF& mousePoint) const;

      private:
        std::unique_ptr<DrawableHandler> m_drawableHandler;
        controller::Controller*          m_actionHandler;
        QPen                             m_drawPen          = QPen(Qt::black, 3);
        MOUSE_POINTER_TYPE               m_mousePointerType = MOUSE_POINTER_TYPE::LINE;
    };
} // namespace model

#endif // GOTIKZ_MODEL_H
