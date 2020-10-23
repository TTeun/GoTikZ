//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_CHANGEGRIDACTION_H
#define GOTIKZ_CHANGEGRIDACTION_H

#include "Action.h"
#include "States/GridState.h"

class ChangeGridAction : public Action {

  public:
    ChangeGridAction(GridState gridState) : Action(ACTION_TYPE::CHANGE_GRID_STATE), m_gridState(gridState) {
    }

    void    doAction(ActionHandler* actionHandler) override;
    QString toString() override;

  private:
    const GridState m_gridState;
};

#endif // GOTIKZ_CHANGEGRIDACTION_H
