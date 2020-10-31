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
    m_drawable->setVisible(true);
    controller->modelHandler()->drawableHandler().addDrawable(m_drawable.release());
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    assert(m_drawable == nullptr);
    controller->draw();
}

void controller::AddPrimitiveAction::undoAction(controller::Controller* controller) {
    m_drawable = static_cast<std::unique_ptr<Drawable>>(
        controller->modelHandler()->drawableHandler().removeDrawable(m_indexOfPrimitive));
    m_drawable->setVisible(false);
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->modelHandler()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}
