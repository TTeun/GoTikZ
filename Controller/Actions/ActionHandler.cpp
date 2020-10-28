//
// Created by pc on 16-10-20.
//

#include "ActionHandler.h"

#include "Action.h"
#include "DeletePrimitiveAction.h"
#include "View/Widgets/MainWidget.h"
#include "MainWindow.h"
#include "View/Widgets/DrawWidget.h"
#include "View/Widgets/GridSettingWidget.h"
#include "View/Widgets/LeftSideBar.h"
#include "View/Widgets/MousePointerTypeSelectWidget.h"
#include "View/Widgets/PenWidget.h"
#include "View/Widgets/RightSideBar.h"

#include <QLayout>

Controller::ActionHandler::ActionHandler(MainWindow* mainWindow) : m_mainWindow(mainWindow) {
}

void Controller::ActionHandler::init(View::MainWidget* mainWidget, Model* model) {
    m_drawWidget   = mainWidget->drawWidget();
    m_leftSideBar  = mainWidget->leftSideBar();
    m_rightSideBar = mainWidget->rightSideBar();
    m_model        = model;

    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &View::MousePointerTypeSelectWidget::undoableActionDone,
                     this, &ActionHandler::addAction);
    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &View::MousePointerTypeSelectWidget::actionDone, this,
                     &ActionHandler::doAction);
    QObject::connect(m_leftSideBar->gridSettingWidget(), &View::GridSettingWidget::actionDone, this,
                     &ActionHandler::doAction);
    QObject::connect(m_leftSideBar->penWidget(), &View::PenWidget::actionDone, this, &ActionHandler::doAction);
}

void Controller::ActionHandler::undoAction() {
    if (m_undoStack.empty()) {
        return;
    }
    m_undoStack.top()->undoAction(this);
    m_redoStack.push(std::move(m_undoStack.top()));
    m_undoStack.pop();
}

void Controller::ActionHandler::redoAction() {
    if (m_redoStack.empty()) {
        return;
    }
    m_redoStack.top()->doAction(this);
    m_undoStack.push(std::move(m_redoStack.top()));
    m_redoStack.pop();
}

void Controller::ActionHandler::addAction(UndoableAction* action, bool isAlreadyDone) {
    if (not isAlreadyDone) {
        action->doAction(this);
    }
    m_undoStack.push(std::unique_ptr<UndoableAction>(action));
    m_redoStack = {};
}

View::DrawWidget* Controller::ActionHandler::drawWidget() {
    return m_drawWidget;
}

void Controller::ActionHandler::doAction(Action* action) {
    action->doAction(this);
    draw();
}

void Controller::ActionHandler::draw() {
    m_mainWindow->repaint();
}

void Controller::ActionHandler::mousePressEvent(QMouseEvent* event) {
    if (!m_mainWindow->hasFocus()) {
        m_mainWindow->setFocus();
    }
    switch (event->buttons()) {
        case Qt::NoButton:
            break;
        case Qt::RightButton:
            m_model->mousePressEvent(event);
            break;
        case Qt::LeftButton:
            m_model->mousePressEvent(event);
            break;
        case Qt::MiddleButton:
            break;
    }

    draw();
}

void Controller::ActionHandler::mouseMoveEvent(QMouseEvent* event) {
    const auto newMousePoint = event->localPos();
    switch (event->buttons()) {
        case Qt::NoButton:
            m_model->mouseMoveEvent(event);
            break;
        case Qt::RightButton:
            m_model->drawableHandler().translateSelected((newMousePoint - m_previousMousePoint) /
                                                         m_drawWidget->transform().scale());
            emit updateRightSideBar();
            break;
        case Qt::LeftButton:
            break;
        case Qt::MiddleButton:
            m_drawWidget->transform().addTranslation(newMousePoint - m_previousMousePoint);
            break;
    }
    draw();
    m_previousMousePoint = event->localPos();
}

void Controller::ActionHandler::wheelEvent(QWheelEvent* event, const QPointF& mousePosition) {
    const auto mouseInWorld = m_model->mousePointInWorldCoordinates(mousePosition);
    m_drawWidget->transform().addToScaleParameter(event->angleDelta().y() / 100);
    m_drawWidget->transform().setTranslation(mousePosition - m_drawWidget->transform().scale() * mouseInWorld);
    draw();
}

Model* Controller::ActionHandler::model() {
    return m_model;
}

void Controller::ActionHandler::keyPressEvent(QKeyEvent* event) {
    qDebug() << "Button pressed" << event->key();
    switch (event->modifiers()) {
        case Qt::NoModifier:
            keyPressEventNoModifier(event);
            break;
        case Qt::ControlModifier:
            keyPressEventWithCtrl(event);
            break;
        default:
            break;
    }
}

void Controller::ActionHandler::keyPressEventNoModifier(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_P:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                MOUSE_POINTER_TYPE::POINT); // Also sends signal
            break;
        case Qt::Key_L:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                MOUSE_POINTER_TYPE::LINE); // Also sends signal
            break;
        case Qt::Key_C:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                MOUSE_POINTER_TYPE::CIRCLE); // Also sends signal
            break;
        case Qt::Key_Y:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                MOUSE_POINTER_TYPE::POLY_LINE); // Also sends signal
            break;
        case Qt::Key_S:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                MOUSE_POINTER_TYPE::SELECT); // Also sends signal
            break;
        case Qt::Key_Escape:
            m_model->drawableHandler().stopStreaming();
            break;
        case Qt::Key_Delete: {
            size_t indexOfSelected = m_model->drawableHandler().indexOfSelectedDrawable();
            if (indexOfSelected != std::numeric_limits<size_t>::max()) {
                addAction(new DeletePrimitiveAction(indexOfSelected), false);
            }
        } break;
        default:
            break;
    }
}

void Controller::ActionHandler::keyPressEventWithCtrl(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Z:
            undoAction();
            break;
        case Qt::Key_R:
            redoAction();
            break;
        default:
            break;
    }
}

void Controller::ActionHandler::setEditWidget(QWidget* widget) {
    widget->setObjectName("EditWidget");
    m_rightSideBar->clearWidget();
    m_rightSideBar->addWidget(widget);
    draw();
}
