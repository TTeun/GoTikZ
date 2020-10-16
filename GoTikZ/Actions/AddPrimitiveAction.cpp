//
// Created by pc on 16-10-20.
//

#include "AddPrimitiveAction.h"

#include "ActionHandler.h"
#include "Widgets/DrawWidget.h"

AddPrimitiveAction::AddPrimitiveAction(size_t indexOfPrimitive)
    : Action(ACTION_TYPE::ADD_PRIMITIVE), m_indexOfPrimitive(indexOfPrimitive) {
}

void AddPrimitiveAction::redoAction(ActionHandler* actionHandler) {
    actionHandler->drawWidget()->m_drawables.push_back(static_cast<std::unique_ptr<Drawable>>(m_drawable.release()));
    assert(m_drawable == nullptr);
    emit actionHandler->drawWidget()->updateSignal();
}

void AddPrimitiveAction::undoAction(ActionHandler* actionHandler) {
    auto& drawables = actionHandler->drawWidget()->m_drawables;
    for (auto it = drawables.begin(); it != drawables.end(); ++it) {
        if ((*it)->index() == m_indexOfPrimitive) {
            m_drawable = static_cast<std::unique_ptr<Drawable>>(it->release());
            assert(it->get() == nullptr);
            drawables.erase(it);
            emit actionHandler->drawWidget()->updateSignal();
            return;
        }
    }
    assert(false);
}

QString AddPrimitiveAction::toString() {
    return "AddPrimitive Action. Index  = " + QString::number(m_indexOfPrimitive);
}
