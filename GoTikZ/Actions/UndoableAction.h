//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_UNDOABLEACTION_H
#define GOTIKZ_UNDOABLEACTION_H

#include "Action.h"

class UndoableAction : public Action {
  protected:
    explicit UndoableAction(ACTION_TYPE type);

  public:
    ~UndoableAction() = default;

    virtual void undoAction(ActionHandler* actionHandler) = 0;
};

#endif // GOTIKZ_UNDOABLEACTION_H
