//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_CHANGEGRIDACTION_H
#define GOTIKZ_CHANGEGRIDACTION_H

#include "Action.h"
#include "View/GridState.h"

namespace controller {
    class Controller;

    class ChangeGridAction : public Action {

      public:
        explicit ChangeGridAction(view::GridState gridState);

        void doAction(Controller* controller) override;

      private:
        const view::GridState m_gridState;
    };
} // namespace controller

#endif // GOTIKZ_CHANGEGRIDACTION_H
