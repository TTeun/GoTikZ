//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_CHANGEGRIDACTION_H
#define GOTIKZ_CHANGEGRIDACTION_H

#include "Action.h"
#include "View/GridState.h"

namespace Controller {
    class ActionHandler;

    class ChangeGridAction : public Action {

      public:
        explicit ChangeGridAction(View::GridState gridState);

        void doAction(ActionHandler* actionHandler) override;

      private:
        const View::GridState m_gridState;
    };
} // namespace Controller

#endif // GOTIKZ_CHANGEGRIDACTION_H
