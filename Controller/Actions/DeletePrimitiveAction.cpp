//
// Created by pc on 28-10-20.
//

#include "DeletePrimitiveAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

Controller::DeletePrimitiveAction::DeletePrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void Controller::DeletePrimitiveAction::doAction(Controller::ActionHandler* actionHandler) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->model()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}

void Controller::DeletePrimitiveAction::undoAction(Controller::ActionHandler* actionHandler) {
    actionHandler->model()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}
