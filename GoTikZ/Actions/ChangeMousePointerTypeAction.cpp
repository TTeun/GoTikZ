//
// Created by pc on 16-10-20.
//

#include "ChangeMousePointerTypeAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"

ChangeMousePointerTypeAction::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive)
    : Action(ACTION_TYPE::CHANGE_MOUSE_POINTER_TYPE), m_newPrimitive(newPrimitive) {
}

void ChangeMousePointerTypeAction::doAction(ActionHandler* actionHandler) {
    actionHandler->model()->setMousePointerType(m_newPrimitive);
}
