//
// Created by pc on 23-10-20.
//

#include "PenChangeAction.h"

#include "../Widgets/DrawWidget.h"
#include "ActionHandler.h"
#include "Model/Model.h"

PenChangeAction::PenChangeAction(QPen pen, size_t indexOfPrimitive)
    : m_pen(std::move(pen)), m_indexOfPrimitive(indexOfPrimitive) {
}

void PenChangeAction::doAction(ActionHandler* actionHandler) {
    if (m_indexOfPrimitive == std::numeric_limits<size_t>::max()) {
        actionHandler->model()->setPen(m_pen);
    } else {
        actionHandler->model()->drawableHandler().setPen(m_pen, m_indexOfPrimitive);
    }
}
