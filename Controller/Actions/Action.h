//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTION_H
#define GOTIKZ_ACTION_H

#include <QString>

namespace controller {
    class Controller;
    class Action {
      protected:
        Action() = default;

      public:
        virtual void doAction(Controller* actionHandler) = 0;
    };
} // namespace controller

#endif // GOTIKZ_ACTION_H
