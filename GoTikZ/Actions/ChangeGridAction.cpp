//
// Created by pc on 23-10-20.
//

#include "ChangeGridAction.h"

#include "ActionHandler.h"

void ChangeGridAction::doAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->setGridState(m_gridState);
}

QString ChangeGridAction::toString() {
    return "Grid change action";
}
