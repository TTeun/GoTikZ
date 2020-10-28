//
// Created by pc on 28-10-20.
//

#include "DeletePrimitiveAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"
#include "Widgets/DrawWidget.h"

DeletePrimitiveAction::DeletePrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void DeletePrimitiveAction::doAction(ActionHandler* actionHandler) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->model()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}

void DeletePrimitiveAction::undoAction(ActionHandler* actionHandler) {
    actionHandler->model()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}
