//
// Created by pc on 16-10-20.
//

#include "ChangeMousePointerTypeAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"

Controller::ChangeMousePointerTypeAction::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive)
    : m_newPrimitive(newPrimitive) {
}

void Controller::ChangeMousePointerTypeAction::doAction(Controller::ActionHandler* actionHandler) {
    actionHandler->model()->setMousePointerType(m_newPrimitive);
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
}
