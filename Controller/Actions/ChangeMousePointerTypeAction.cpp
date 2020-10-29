//
// Created by pc on 16-10-20.
//

#include "ChangeMousePointerTypeAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "Model/MousePointerTypeEnum.h"

controller::ChangeMousePointerTypeAction::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive)
    : m_mousePointerType(newPrimitive) {
}

void controller::ChangeMousePointerTypeAction::doAction(controller::Controller* actionHandler) {
    actionHandler->modelHandler()->setMousePointerType(m_mousePointerType);
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
}
