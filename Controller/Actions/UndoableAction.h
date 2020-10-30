//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_UNDOABLEACTION_H
#define GOTIKZ_UNDOABLEACTION_H

#include "Action.h"

namespace controller {
    class Controller;
    class UndoableAction : public controller::Action {
      protected:
        explicit UndoableAction();

      public:
        ~UndoableAction() = default;

        virtual void undoAction(Controller* controller) = 0;
    };
} // namespace controller

#endif // GOTIKZ_UNDOABLEACTION_H
