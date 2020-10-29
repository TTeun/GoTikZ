//
// Created by pc on 16-10-20.
//

#include "ActionHandler.h"

#include "Controller/Actions/DeletePrimitiveAction.h"
#include "Controller/Actions/TranslatePrimitiveAction.h"
#include "Controller/Actions/UndoableAction.h"
#include "Controller/ModifierState.h"
#include "MainWindow.h"
#include "Model/ModelHandler.h"
#include "Model/MousePointerTypeEnum.h"
#include "View/Widgets/DrawWidget.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/GridSettingWidget.h"
#include "View/Widgets/LeftSideBar.h"
#include "View/Widgets/MainWidget.h"
#include "View/Widgets/MousePointerTypeSelectWidget.h"
#include "View/Widgets/PenWidget.h"
#include "View/Widgets/RightSideBar.h"

#include <QLayout>

Controller::ActionHandler::ActionHandler(MainWindow* mainWindow) : m_mainWindow(mainWindow) {
}

void Controller::ActionHandler::init(View::MainWidget* mainWidget, Model::ModelHandler* model) {
    m_drawWidget   = mainWidget->drawWidget();
    m_leftSideBar  = mainWidget->leftSideBar();
    m_rightSideBar = mainWidget->rightSideBar();
    m_modelHandler = model;

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
            m_rightClickedMousePoint = event->localPos();
            m_modelHandler->mouseRightClick(event->localPos(), m_modifierState);
            break;
        case Qt::LeftButton:
            m_modelHandler->mouseLeftClick(event->localPos());
            break;
        case Qt::MiddleButton:
            break;
    }
    draw();
}

void Controller::ActionHandler::mouseReleaseEvent(QMouseEvent* event) {
    switch (event->button()) {
        case Qt::NoButton:
            break;
        case Qt::LeftButton:
            break;
        case Qt::RightButton:
            if (not m_modelHandler->drawableHandler().selectedDrawables().empty() &&
                event->localPos() != m_rightClickedMousePoint) {
                std::vector<size_t> indicesOfTranslatedPrimitives;
                indicesOfTranslatedPrimitives.reserve(m_modelHandler->drawableHandler().selectedDrawables().size());
                for (const auto& el : m_modelHandler->drawableHandler().selectedDrawables()) {
                    indicesOfTranslatedPrimitives.push_back(el->index());
                }
                addAction(new TranslatePrimitiveAction(indicesOfTranslatedPrimitives,
                                                       (event->localPos() - m_rightClickedMousePoint) /
                                                           m_drawWidget->transform().scale()),
                          true);
            }

            break;
        case Qt::MidButton:
            break;
        default:
            break;
    }
}

void Controller::ActionHandler::mouseMoveEvent(QMouseEvent* event) {
    const auto newMousePoint = event->localPos();
    switch (event->buttons()) {
        case Qt::NoButton:
            m_modelHandler->mouseMoveEvent(newMousePoint);
            break;
        case Qt::RightButton:
            m_modelHandler->drawableHandler().translateSelected((newMousePoint - m_previousFrameMousePoint) /
                                                                m_drawWidget->transform().scale());
            emit updateRightSideBar();
            break;
        case Qt::LeftButton:
            m_modelHandler->mouseMoveEvent(newMousePoint);
            break;
        case Qt::MiddleButton:
            m_drawWidget->transform().addTranslation(newMousePoint - m_previousFrameMousePoint);
            break;
    }
    draw();
    m_previousFrameMousePoint = newMousePoint;
}

void Controller::ActionHandler::wheelEvent(QWheelEvent* event, const QPointF& mousePosition) {
    const auto mouseInWorld = m_modelHandler->mousePointInWorldCoordinates(mousePosition);
    m_drawWidget->transform().addToScaleParameter(event->angleDelta().y() / 100);
    m_drawWidget->transform().setTranslation(mousePosition - m_drawWidget->transform().scale() * mouseInWorld);
    draw();
}

Model::ModelHandler* Controller::ActionHandler::modelHandler() {
    return m_modelHandler;
}

void Controller::ActionHandler::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Shift) {
        m_modifierState.m_shiftPressed = true;
    } else if (event->key() == Qt::Key_Control) {
        m_modifierState.m_controlPressed = true;
    }

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
                Model::MOUSE_POINTER_TYPE::POINT); // Also sends signal
            break;
        case Qt::Key_L:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                Model::MOUSE_POINTER_TYPE::LINE); // Also sends signal
            break;
        case Qt::Key_C:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                Model::MOUSE_POINTER_TYPE::CIRCLE); // Also sends signal
            break;
        case Qt::Key_Y:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                Model::MOUSE_POINTER_TYPE::POLY_LINE); // Also sends signal
            break;
        case Qt::Key_S:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                Model::MOUSE_POINTER_TYPE::SELECT); // Also sends signal
            break;
        case Qt::Key_Escape:
            m_modelHandler->drawableHandler().stopStreaming();
            break;
        case Qt::Key_Delete: {
            size_t indexOfSelected = m_modelHandler->drawableHandler().indexOfSelectedDrawable();
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
    QObject::connect(this, &Controller::ActionHandler::updateRightSideBar,
                     dynamic_cast<View::DrawableEditWidget*>(widget), &View::DrawableEditWidget::needsUpdate);

    draw();
}

void Controller::ActionHandler::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Shift) {
        m_modifierState.m_shiftPressed = false;
    } else if (event->key() == Qt::Key_Control) {
        m_modifierState.m_controlPressed = false;
    }
}
