//
// Created by pc on 16-10-20.
//

#include "ChangeMousePointerTypeAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"

ChangeMousePointerTypeAction::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive)
    : m_newPrimitive(newPrimitive) {
}

void ChangeMousePointerTypeAction::doAction(ActionHandler* actionHandler) {
    actionHandler->model()->setMousePointerType(m_newPrimitive);
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
}
