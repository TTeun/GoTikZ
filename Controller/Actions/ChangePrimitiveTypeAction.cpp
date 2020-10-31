//
// Created by pc on 16-10-20.
//

#include "ChangePrimitiveTypeAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "Model/PrimitiveTypeEnum.h"

controller::ChangePrimitiveTypeAction::ChangePrimitiveTypeAction(PRIMITIVE_TYPE newPrimitive)
    : m_mousePointerType(newPrimitive) {
}

void controller::ChangePrimitiveTypeAction::doAction(controller::Controller* controller) {
    controller->model()->setMousePointerType(m_mousePointerType);
    controller->model()->drawableHandler().clearSelectedAndHighlighted();
}
