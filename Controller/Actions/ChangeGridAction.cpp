//
// Created by pc on 23-10-20.
//

#include "ChangeGridAction.h"

#include "ActionHandler.h"
#include "View/Widgets/DrawWidget.h"

Controller::ChangeGridAction::ChangeGridAction(View::GridState gridState) : m_gridState(gridState) {
}

void Controller::ChangeGridAction::doAction(Controller::ActionHandler* actionHandler) {
    actionHandler->drawWidget()->setGridState(m_gridState);
    actionHandler->draw();
}
