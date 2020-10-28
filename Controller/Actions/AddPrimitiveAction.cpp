//
// Created by pc on 16-10-20.
//

#include "AddPrimitiveAction.h"

#include "ActionHandler.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

Controller::AddPrimitiveAction::AddPrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void Controller::AddPrimitiveAction::doAction(Controller::ActionHandler* actionHandler) {
    qDebug() << "Do";
    actionHandler->model()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}

void Controller::AddPrimitiveAction::undoAction(Controller::ActionHandler* actionHandler) {
    qDebug() << "Undo";
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->model()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->model()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}
