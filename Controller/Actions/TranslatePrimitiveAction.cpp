//
// Created by pc on 29-10-20.
//

#include "TranslatePrimitiveAction.h"

#include "Controller/Actions/ActionHandler.h"
#include "Drawable/DrawableHandler.h"
#include "Model/ModelHandler.h"

#include <utility>

Controller::TranslatePrimitiveAction::TranslatePrimitiveAction(std::vector<size_t> mIndices,
                                                               const QPointF&      mTranslation)
    : m_indices(std::move(mIndices)), m_translation(mTranslation) {
    assert(not m_indices.empty());
}

void Controller::TranslatePrimitiveAction::doAction(Controller::ActionHandler* actionHandler) {
    for (auto index : m_indices) {
        actionHandler->modelHandler()->drawableHandler().translate(index, m_translation);
    }
    actionHandler->draw();
}

void Controller::TranslatePrimitiveAction::undoAction(Controller::ActionHandler* actionHandler) {
    for (auto index : m_indices) {
        actionHandler->modelHandler()->drawableHandler().translate(index, -m_translation);
    }
    actionHandler->draw();
}
