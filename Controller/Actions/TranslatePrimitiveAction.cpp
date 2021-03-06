//
// Created by pc on 29-10-20.
//

#include "Controller/Actions/TranslatePrimitiveAction.h"

#include "Controller/Controller.h"
#include "Drawable/DrawableHandler.h"
#include "Model/Model.h"

#include <utility>

controller::TranslatePrimitiveAction::TranslatePrimitiveAction(std::vector<size_t> mIndices,
                                                               const QPointF&      mTranslation)
    : m_indices(std::move(mIndices)), m_translation(mTranslation) {
    assert(not m_indices.empty());
}

void controller::TranslatePrimitiveAction::doAction(controller::Controller* controller) {
    for (auto index : m_indices) {
        controller->model()->drawableHandler().translate(index, m_translation);
    }
    controller->updateControlPoints();
    controller->draw();
}

void controller::TranslatePrimitiveAction::undoAction(controller::Controller* controller) {
    for (auto index : m_indices) {
        controller->model()->drawableHandler().translate(index, -m_translation);
    }
    controller->updateControlPoints();
    controller->draw();
}
