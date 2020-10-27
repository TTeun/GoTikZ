//
// Created by pc on 23-10-20.
//

#include "ChangeGridAction.h"

#include "../Widgets/DrawWidget.h"
#include "ActionHandler.h"

ChangeGridAction::ChangeGridAction(GridState gridState) : m_gridState(gridState) {
}

void ChangeGridAction::doAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->setGridState(m_gridState);
    actionHandler->draw();
}
