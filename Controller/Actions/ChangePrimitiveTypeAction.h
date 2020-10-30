//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEPRIMITIVETYPEACTION_H
#define GOTIKZ_CHANGEPRIMITIVETYPEACTION_H

#include "Action.h"
#include "Model/PrimitiveTypeEnum.h"

namespace controller {
    class Controller;

    class ChangePrimitiveTypeAction : public Action {

      public:
        explicit ChangePrimitiveTypeAction(PRIMITIVE_TYPE newPrimitive);
        void doAction(Controller* controller) override;

      private:
        const PRIMITIVE_TYPE m_mousePointerType;
    };
} // namespace controller

#endif // GOTIKZ_CHANGEPRIMITIVETYPEACTION_H
