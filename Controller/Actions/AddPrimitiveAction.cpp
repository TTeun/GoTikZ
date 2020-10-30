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

void controller::AddPrimitiveAction::doAction(controller::Controller* controller) {
    qDebug() << "Do";
    controller->modelHandler()->drawableHandler().addDrawable(m_drawable.release());
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    controller->draw();
}

void controller::AddPrimitiveAction::undoAction(controller::Controller* controller) {
    qDebug() << "Undo";
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        controller->modelHandler()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}
