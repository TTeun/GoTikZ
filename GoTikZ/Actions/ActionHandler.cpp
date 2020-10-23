//
// Created by pc on 16-10-20.
//

#include "ActionHandler.h"

#include <QDebug>
#include <Widgets/DrawWidget.h>
#include <Widgets/PrimitiveSelectWidget.h>

void ActionHandler::undoAction() {
    if (m_undoStack.empty()) {
        return;
    }
    m_undoStack.top()->undoAction(this);
    m_redoStack.push(std::move(m_undoStack.top()));
    m_undoStack.pop();
}

void ActionHandler::redoAction() {
    if (m_redoStack.empty()) {
        return;
    }
    m_redoStack.top()->doAction(this);
    m_undoStack.push(std::move(m_redoStack.top()));
    m_redoStack.pop();
}

void ActionHandler::addAction(UndoableAction* action, bool isAlreadyDone, bool canBeUndone) {
    if (not isAlreadyDone) {
        action->doAction(this);
    }
    if (canBeUndone) {
        qDebug() << "Added an action: " + action->toString();
        m_undoStack.push(std::unique_ptr<UndoableAction>(action));
        m_redoStack = {};
    }
}

ActionHandler::ActionHandler(DrawWidget* drawWidget, PrimitiveSelectWidget* primitiveTypeSelectWidget)
    : m_drawWidget(drawWidget), m_primitiveTypeSelectWidget(primitiveTypeSelectWidget) {
    QObject::connect(m_drawWidget, &DrawWidget::undoableActionDone, this, &ActionHandler::addAction);
    QObject::connect(primitiveTypeSelectWidget, &PrimitiveSelectWidget::undoableActionDone, this,
                     &ActionHandler::addAction);
    QObject::connect(primitiveTypeSelectWidget, &PrimitiveSelectWidget::actionDone, this, &ActionHandler::doAction);
}

DrawWidget* ActionHandler::drawWidget() {
    return m_drawWidget;
}

PrimitiveSelectWidget* ActionHandler::primitiveTypeSelectWidget() {
    return m_primitiveTypeSelectWidget;
}

void ActionHandler::doAction(Action* action) {
    action->doAction(this);
    qDebug() << "AdsaDA";
}
