//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTION_H
#define GOTIKZ_ACTION_H

#include <QString>

class ActionHandler;

class Action {
  protected:
    Action() = default;

  public:
    virtual void doAction(ActionHandler* actionHandler) = 0;
};

#endif // GOTIKZ_ACTION_H
