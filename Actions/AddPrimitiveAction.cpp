//
// Created by pc on 16-10-20.
//

#include "AddPrimitiveAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"
#include "Widgets/DrawWidget.h"

AddPrimitiveAction::AddPrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void AddPrimitiveAction::doAction(ActionHandler* actionHandler) {
    actionHandler->model()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}

void AddPrimitiveAction::undoAction(ActionHandler* actionHandler) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->model()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}
