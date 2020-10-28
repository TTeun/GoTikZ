//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTION_H
#define GOTIKZ_ACTION_H

#include <QString>

namespace Controller {
    class ActionHandler;
} // namespace Controller

class Action {
  protected:
    Action() = default;

  public:
    virtual void doAction(Controller::ActionHandler* actionHandler) = 0;
};

#endif // GOTIKZ_ACTION_H
