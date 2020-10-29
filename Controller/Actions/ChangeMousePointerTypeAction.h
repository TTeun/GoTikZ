//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
#define GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H

#include "Action.h"
#include "Model/MousePointerTypeEnum.h"

namespace Controller {
    class ActionHandler;

    class ChangeMousePointerTypeAction : public Action {

      public:
        explicit ChangeMousePointerTypeAction(Model::MOUSE_POINTER_TYPE newPrimitive);
        void doAction(ActionHandler* actionHandler) override;

      private:
        const Model::MOUSE_POINTER_TYPE m_mousePointerType;
    };
} // namespace Controller

#endif // GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
