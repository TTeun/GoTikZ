//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
#define GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H

#include "Action.h"
#include "Model/MousePointerTypeEnum.h"

namespace controller {
    class Controller;

    class ChangeMousePointerTypeAction : public Action {

      public:
        explicit ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive);
        void doAction(Controller* actionHandler) override;

      private:
        const MOUSE_POINTER_TYPE m_mousePointerType;
    };
} // namespace controller

#endif // GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
