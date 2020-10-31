//
// Created by pc on 28-10-20.
//

#include "DeletePrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

#include <utility>

controller::DeletePrimitiveAction::DeletePrimitiveAction(std::vector<size_t> indices) : m_indices(std::move(indices)) {
}

void controller::DeletePrimitiveAction::doAction(controller::Controller* controller) {
    assert(m_drawables.empty());
    for (auto index : m_indices) {
        m_drawables.push_back(static_cast<std::unique_ptr<Drawable>>(
            controller->modelHandler()->drawableHandler().removeDrawable(index)));
    }

    for (auto& el : m_drawables) {
        el->setVisible(false);
    }

    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}

void controller::DeletePrimitiveAction::undoAction(controller::Controller* controller) {
    for (auto& el : m_drawables) {
        el->setVisible(true);
        controller->modelHandler()->drawableHandler().addDrawable(el.release());
    }
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    for (auto& el : m_drawables) {
        assert(el.get() == nullptr);
    }
    m_drawables.clear();
    controller->draw();
}
