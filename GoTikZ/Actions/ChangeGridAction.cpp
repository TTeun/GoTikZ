//
// Created by pc on 23-10-20.
//

#include "ChangeGridAction.h"

#include "../Widgets/DrawWidget.h"
#include "ActionHandler.h"

ChangeGridAction::ChangeGridAction(GridState gridState)
    : Action(ACTION_TYPE::CHANGE_GRID_STATE), m_gridState(gridState) {
}

void ChangeGridAction::doAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->setGridState(m_gridState);
    actionHandler->draw();
}
