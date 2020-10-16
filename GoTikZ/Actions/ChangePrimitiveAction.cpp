//
// Created by pc on 16-10-20.
//

#include "ChangePrimitiveAction.h"

#include "ActionHandler.h"

ChangePrimitiveAction::ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE newPrimitive)
    : Action(ACTION_TYPE::CHANGE_PRIMITIVE_TYPE), m_newPrimitive(newPrimitive) {
}

void ChangePrimitiveAction::redoAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->setPrimitiveType(m_newPrimitive);
}

QString ChangePrimitiveAction::toString() {
    return QString("Change primitive type");
}

void ChangePrimitiveAction::undoAction(ActionHandler* actionHandler) {
    assert(false);
}
