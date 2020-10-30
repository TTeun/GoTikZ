//
// Created by pc on 28-10-20.
//

#include "DeletePrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

controller::DeletePrimitiveAction::DeletePrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void controller::DeletePrimitiveAction::doAction(controller::Controller* controller) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        controller->modelHandler()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}

void controller::DeletePrimitiveAction::undoAction(controller::Controller* controller) {
    controller->modelHandler()->drawableHandler().addDrawable(m_drawable.release());
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    controller->draw();
}
