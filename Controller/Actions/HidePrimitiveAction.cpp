//
// Created by pc on 28-10-20.
//

#include "HidePrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

#include <utility>

controller::HidePrimitiveAction::HidePrimitiveAction(std::vector<size_t> indices) : m_indices(std::move(indices)) {
}

void controller::HidePrimitiveAction::doAction(controller::Controller* controller) {
    for (auto& el : controller->model()->drawableHandler().drawables()) {
        if (std::find_if(m_indices.begin(), m_indices.end(),
                         [&](const size_t index) { return el->index() == index; }) != m_indices.end()) {
            assert(el->visible());
            el->setVisible(false);
        }
    }
    controller->setSelectedControlPoint(nullptr);
    controller->model()->drawableHandler().clearSelectedAndHighlighted();
    controller->updateControlPoints();
    controller->draw();
}

void controller::HidePrimitiveAction::undoAction(controller::Controller* controller) {
    for (auto& el : controller->model()->drawableHandler().drawables()) {
        if (std::find_if(m_indices.begin(), m_indices.end(),
                         [&](const size_t index) { return el->index() == index; }) != m_indices.end()) {
            assert(el->visible() == false);
            el->setVisible(true);
        }
    }
    controller->setSelectedControlPoint(nullptr);
    controller->model()->drawableHandler().clearSelectedAndHighlighted();
    controller->updateControlPoints();
    controller->draw();
}
