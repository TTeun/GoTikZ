//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_UNDOABLEACTION_H
#define GOTIKZ_UNDOABLEACTION_H

#include "Action.h"

namespace Controller {
class ActionHandler;
}

class UndoableAction : public Action {
  protected:
    explicit UndoableAction();

  public:
    ~UndoableAction() = default;

    virtual void undoAction(Controller::ActionHandler* actionHandler) = 0;
};

#endif // GOTIKZ_UNDOABLEACTION_H
