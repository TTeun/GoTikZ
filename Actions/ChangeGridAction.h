//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_CHANGEGRIDACTION_H
#define GOTIKZ_CHANGEGRIDACTION_H

#include "Action.h"
#include "States/GridState.h"

class ChangeGridAction : public Action {

  public:
    explicit ChangeGridAction(GridState gridState);

    void doAction(ActionHandler* actionHandler) override;

  private:
    const GridState m_gridState;
};

#endif // GOTIKZ_CHANGEGRIDACTION_H
