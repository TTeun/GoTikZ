//
// Created by pc on 16-10-20.
//

#include "ChangePrimitiveAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"

ChangePrimitiveAction::ChangePrimitiveAction(Drawable::PRIMITIVE_TYPE newPrimitive)
    : Action(ACTION_TYPE::CHANGE_PRIMITIVE_TYPE), m_newPrimitive(newPrimitive) {
}

void ChangePrimitiveAction::doAction(ActionHandler* actionHandler) {
    actionHandler->model()->setPrimitiveType(m_newPrimitive);
}
