//
// Created by pc on 28-10-20.
//

#include "DeletePrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

controller::DeletePrimitiveAction::DeletePrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void controller::DeletePrimitiveAction::doAction(controller::Controller* actionHandler) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->modelHandler()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}

void controller::DeletePrimitiveAction::undoAction(controller::Controller* actionHandler) {
    actionHandler->modelHandler()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}
