//
// Created by pc on 16-10-20.
//

#include "AddPrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

#include <QDebug>

controller::AddPrimitiveAction::AddPrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void controller::AddPrimitiveAction::doAction(controller::Controller* actionHandler) {
    qDebug() << "Do";
    actionHandler->modelHandler()->drawableHandler().addDrawable(m_drawable.release());
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    actionHandler->draw();
}

void controller::AddPrimitiveAction::undoAction(controller::Controller* actionHandler) {
    qDebug() << "Undo";
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        actionHandler->modelHandler()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    actionHandler->draw();
}
