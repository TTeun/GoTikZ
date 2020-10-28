//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_UNDOABLEACTION_H
#define GOTIKZ_UNDOABLEACTION_H

#include "Action.h"

namespace Controller {
    class ActionHandler;
    class UndoableAction : public Controller::Action {
      protected:
        explicit UndoableAction();

      public:
        ~UndoableAction() = default;

        virtual void undoAction(ActionHandler* actionHandler) = 0;
    };
} // namespace Controller

#endif // GOTIKZ_UNDOABLEACTION_H
