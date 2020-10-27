//
// Created by pc on 23-10-20.
//

#include "PenChangeAction.h"

#include "../Widgets/DrawWidget.h"
#include "ActionHandler.h"
#include "Model/Model.h"

PenChangeAction::PenChangeAction(const QPen& pen, size_t indexOfPrimitive)
    : Action(ACTION_TYPE::CHANGE_PEN), m_pen(pen), m_indexOfPrimitive(indexOfPrimitive) {
}

void PenChangeAction::doAction(ActionHandler* actionHandler) {
    actionHandler->model()->setPen(m_pen);
}
