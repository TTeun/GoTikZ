//
// Created by pc on 23-10-20.
//

#include "PenChangeAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

controller::PenChangeAction::PenChangeAction(QPen pen, size_t indexOfPrimitive)
    : m_pen(std::move(pen)), m_indexOfPrimitive(indexOfPrimitive) {
}

void controller::PenChangeAction::doAction(controller::Controller* controller) {
    if (m_indexOfPrimitive == std::numeric_limits<size_t>::max()) {
        controller->model()->setPen(m_pen);
    } else {
        controller->model()->drawableHandler().setPen(m_pen, m_indexOfPrimitive);
    }
}
