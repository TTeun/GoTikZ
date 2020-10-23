//
// Created by pc on 16-10-20.
//

#include "ActionHandler.h"

#include "Widgets/DrawWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/PrimitiveSelectWidget.h"

#include <QDebug>

ActionHandler::ActionHandler(DrawWidget* drawWidget, LeftSideBar* leftSideBar)
    : m_drawWidget(drawWidget), m_leftSideBar(leftSideBar) {
}

void ActionHandler::init() {
    QObject::connect(m_drawWidget, &DrawWidget::undoableActionDone, this, &ActionHandler::addAction);
    QObject::connect(m_leftSideBar->primitiveSelectWidget(), &PrimitiveSelectWidget::undoableActionDone, this,
                     &ActionHandler::addAction);
    QObject::connect(m_leftSideBar->primitiveSelectWidget(), &PrimitiveSelectWidget::actionDone, this,
                     &ActionHandler::doAction);
    QObject::connect(m_leftSideBar->gridSettingWidget(), &GridSettingWidget::actionDone, this,
                     &ActionHandler::doAction);
    QObject::connect(m_leftSideBar->penWidget(), &PenWidget::actionDone, this, &ActionHandler::doAction);
}

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

void ActionHandler::addAction(UndoableAction* action, bool isAlreadyDone) {
    if (not isAlreadyDone) {
        action->doAction(this);
    }
    qDebug() << "Added an action: " + action->toString();
    m_undoStack.push(std::unique_ptr<UndoableAction>(action));
    m_redoStack = {};
}

DrawWidget* ActionHandler::drawWidget() {
    return m_drawWidget;
}

PrimitiveSelectWidget* ActionHandler::primitiveTypeSelectWidget() {
    return m_leftSideBar->primitiveSelectWidget();
}

void ActionHandler::doAction(Action* action) {
    action->doAction(this);
}
