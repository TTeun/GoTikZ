//
// Created by pc on 16-10-20.
//

#include "AddPrimitiveAction.h"

#include "ActionHandler.h"
#include "Widgets/DrawWidget.h"

AddPrimitiveAction::AddPrimitiveAction(size_t indexOfPrimitive)
    : UndoableAction(ACTION_TYPE::ADD_PRIMITIVE), m_indexOfPrimitive(indexOfPrimitive) {
}

void AddPrimitiveAction::doAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->addDrawable(m_drawable.release());
    assert(m_drawable == nullptr);
    actionHandler->draw();
}

void AddPrimitiveAction::undoAction(ActionHandler* actionHandler) {
    m_drawable =
        static_cast<std::unique_ptr<Drawable>>(actionHandler->drawWidget()->removeDrawable(m_indexOfPrimitive));
    actionHandler->draw();
}
