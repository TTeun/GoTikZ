//
// Created by pc on 16-10-20.
//

#include "Controller.h"

#include "Controller/Actions/AddPrimitiveAction.h"
#include "Controller/Actions/DeletePrimitiveAction.h"
#include "Controller/Actions/TranslatePrimitiveAction.h"
#include "Controller/Actions/UndoableAction.h"
#include "MainWindow.h"
#include "Model/Model.h"
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

controller::Controller::Controller(MainWindow* mainWindow) : m_mainWindow(mainWindow) {
}

void controller::Controller::init(view::MainWidget* mainWidget, model::Model* model) {
    m_drawWidget   = mainWidget->drawWidget();
    m_leftSideBar  = mainWidget->leftSideBar();
    m_rightSideBar = mainWidget->rightSideBar();
    m_modelHandler = model;

    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &view::MousePointerTypeSelectWidget::undoableActionDone,
                     this, &Controller::addAction);
    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &view::MousePointerTypeSelectWidget::actionDone, this,
                     &Controller::doAction);
    QObject::connect(m_leftSideBar->gridSettingWidget(), &view::GridSettingWidget::actionDone, this,
                     &Controller::doAction);
    QObject::connect(m_leftSideBar->penWidget(), &view::PenWidget::actionDone, this, &Controller::doAction);
}

void controller::Controller::undoAction() {
    if (m_undoStack.empty()) {
        return;
    }
    m_undoStack.top()->undoAction(this);
    m_redoStack.push(std::move(m_undoStack.top()));
    m_undoStack.pop();
}

void controller::Controller::redoAction() {
    if (m_redoStack.empty()) {
        return;
    }
    m_redoStack.top()->doAction(this);
    m_undoStack.push(std::move(m_redoStack.top()));
    m_redoStack.pop();
}

void controller::Controller::addAction(UndoableAction* action, bool isAlreadyDone) {
    if (not isAlreadyDone) {
        action->doAction(this);
    }
    m_undoStack.push(std::unique_ptr<UndoableAction>(action));
    m_redoStack = {};
}

view::DrawWidget* controller::Controller::drawWidget() {
    return m_drawWidget;
}

void controller::Controller::doAction(Action* action) {
    action->doAction(this);
    draw();
}

void controller::Controller::draw() {
    m_mainWindow->repaint();
}

void controller::Controller::mousePressEvent(QMouseEvent* event) {
    if (!m_mainWindow->hasFocus()) {
        m_mainWindow->setFocus();
    }
    switch (event->buttons()) {
        case Qt::NoButton:
            break;
        case Qt::RightButton:
            leftClickEvent(event);
            break;
        case Qt::LeftButton:
            rightClickEvent(event);
            break;
        case Qt::MiddleButton:
            break;
    }
    draw();
}

void controller::Controller::mouseReleaseEvent(QMouseEvent* event) {
    switch (event->button()) {
        case Qt::BackButton:
            undoAction();
            break;
        case Qt::ForwardButton:
            redoAction();
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
        default:
            break;
    }
}

void controller::Controller::mouseMoveEvent(QMouseEvent* event) {
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

void controller::Controller::wheelEvent(QWheelEvent* event, const QPointF& mousePosition) {
    const auto mouseInWorld = m_modelHandler->mousePointInWorldCoordinates(mousePosition);
    m_drawWidget->transform().addToScaleParameter(event->angleDelta().y() / 100);
    m_drawWidget->transform().setTranslation(mousePosition - m_drawWidget->transform().scale() * mouseInWorld);
    draw();
}

model::Model* controller::Controller::modelHandler() {
    return m_modelHandler;
}

void controller::Controller::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Shift) {
        m_modifierState.setShiftPressed(true);
    } else if (event->key() == Qt::Key_Control) {
        m_modifierState.setControlPress(true);
    }

    switch (event->modifiers()) {
        case Qt::NoModifier:
            keyPressEventNoModifier(event);
            break;
        case Qt::ControlModifier:
            keyPressEventWithControl(event);
            break;
        case Qt::ControlModifier | Qt::ShiftModifier:
            keyPressEventWithControlAndShift(event);
            break;
        default:
            break;
    }
}

void controller::Controller::keyPressEventNoModifier(QKeyEvent* event) {
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

void controller::Controller::keyPressEventWithControl(QKeyEvent* event) {
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

void controller::Controller::keyPressEventWithControlAndShift(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Z:
            redoAction();
            break;
        default:
            break;
    }
}

void controller::Controller::setEditWidget(QWidget* widget) {
    widget->setObjectName("EditWidget");
    m_rightSideBar->clearWidget();
    m_rightSideBar->addWidget(widget);
    QObject::connect(this, &controller::Controller::updateRightSideBar, dynamic_cast<view::DrawableEditWidget*>(widget),
                     &view::DrawableEditWidget::needsUpdate);

    draw();
}

void controller::Controller::keyReleaseEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Shift) {
        m_modifierState.setShiftPressed(false);
    } else if (event->key() == Qt::Key_Control) {
        m_modifierState.setControlPress(false);
    }
}

void controller::Controller::rightClickEvent(QMouseEvent* event) {
    const auto leftClickedMousePoint = event->localPos();
    if (m_modifierState.controlPressed()) {
        if (m_modifierState.shiftPressed()) {
            m_modelHandler->addToSelected(leftClickedMousePoint);
        } else {
            m_modelHandler->selectNew(leftClickedMousePoint);
        }
    } else {
        m_modelHandler->setPoint(leftClickedMousePoint, m_modifierState);
        m_rightSideBar->clearWidget();
    }
}

void controller::Controller::leftClickEvent(QMouseEvent* event) {
    m_rightClickedMousePoint = event->localPos();
    if (m_modelHandler->drawableHandler().isStreaming()) {
        m_modelHandler->drawableHandler().addPointToStreamDrawable(
            m_modelHandler->drawableHandler().snap(m_rightClickedMousePoint), true);
        addAction(new controller::AddPrimitiveAction(m_modelHandler->drawableHandler().drawables().back()->index()),
                  true);
    }
}