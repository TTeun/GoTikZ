//
// Created by pc on 16-10-20.
//

#include "ChangeMousePointerTypeAction.h"

#include "ActionHandler.h"
#include "Model/ModelHandler.h"
#include "Model/MousePointerTypeEnum.h"

Controller::ChangeMousePointerTypeAction::ChangeMousePointerTypeAction(Model::MOUSE_POINTER_TYPE newPrimitive)
    : m_mousePointerType(newPrimitive) {
}

void Controller::ChangeMousePointerTypeAction::doAction(Controller::ActionHandler* actionHandler) {
    actionHandler->modelHandler()->setMousePointerType(m_mousePointerType);
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
}
