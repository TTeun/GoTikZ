//
// Created by pc on 23-10-20.
//

#include "ChangeGridAction.h"

#include "Controller/Controller.h"
#include "View/Widgets/DrawWidget.h"

controller::ChangeGridAction::ChangeGridAction(view::GridState gridState) : m_gridState(gridState) {
}

void controller::ChangeGridAction::doAction(controller::Controller* controller) {
    controller->drawWidget()->setGridState(m_gridState);
    controller->draw();
}
