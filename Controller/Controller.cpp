//
// Created by pc on 16-10-20.
//

#include "Controller.h"

#include "Controller/Actions/HidePrimitiveAction.h"
#include "Controller/Actions/ShowPrimitiveAction.h"
#include "Controller/Actions/TranslateControlPointAction.h"
#include "Controller/Actions/TranslatePrimitiveAction.h"
#include "Controller/Actions/UndoableAction.h"
#include "Drawable/Circle.h"
#include "Drawable/ControlPoint/ControlPoint.h"
#include "Drawable/Line.h"
#include "Drawable/Point.h"
#include "Drawable/PolyLine.h"
#include "MainWindow.h"
#include "Model/Model.h"
#include "Model/PrimitiveTypeEnum.h"
#include "View/Widgets/DrawWidget.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidgetFactory.h"
#include "View/Widgets/GridSettingWidget.h"
#include "View/Widgets/LeftSideBar.h"
#include "View/Widgets/MainWidget.h"
#include "View/Widgets/PenWidget.h"
#include "View/Widgets/PrimitiveTypeSelectWidget.h"
#include "View/Widgets/RightSideBar.h"

#include <QLayout>

controller::Controller::Controller(MainWindow* mainWindow) : m_mainWindow(mainWindow) {
}

void controller::Controller::init(view::MainWidget* mainWidget, model::Model* model) {
    m_drawWidget   = mainWidget->drawWidget();
    m_leftSideBar  = mainWidget->leftSideBar();
    m_rightSideBar = mainWidget->rightSideBar();
    m_model        = model;
    m_coordinateConverter.reset(
        new controller::CoordinateConverter(&m_drawWidget->transform(), &m_model->drawableHandler()));

    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &view::PrimitiveTypeSelectWidget::undoableActionDone,
                     this, &Controller::addAction);
    QObject::connect(m_leftSideBar->mousePointerTypeSelect(), &view::PrimitiveTypeSelectWidget::actionDone, this,
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
            rightClickEvent(event);
            break;
        case Qt::LeftButton:
            leftClickEvent(event);
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
            if (m_selectedControlPoint != nullptr) {
                addAction(new TranslateControlPointAction(m_selectedControlPoint->index(),
                                                          (event->localPos() - m_rightClickedMousePosition) /
                                                              m_drawWidget->transform().scale()),
                          true);

            } else if (not m_model->drawableHandler().selectedDrawables().empty()) {
                std::vector<size_t> indicesOfTranslatedPrimitives;
                indicesOfTranslatedPrimitives.reserve(m_model->drawableHandler().selectedDrawables().size());
                for (const auto& el : m_model->drawableHandler().selectedDrawables()) {
                    indicesOfTranslatedPrimitives.push_back(el->index());
                }
                addAction(new TranslatePrimitiveAction(indicesOfTranslatedPrimitives,
                                                       (event->localPos() - m_rightClickedMousePosition) /
                                                           m_drawWidget->transform().scale()),
                          true);
            } else if (m_model->drawableHandler().highlightedDrawable()) {
                addAction(new TranslatePrimitiveAction({m_model->drawableHandler().highlightedDrawable()->index()},
                                                       (event->localPos() - m_rightClickedMousePosition) /
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
            m_model->mouseMoveEvent(newMousePoint);
            break;
        case Qt::RightButton:
            rightMouseMoveEvent(newMousePoint);
            break;
        case Qt::LeftButton:
            m_model->mouseMoveEvent(newMousePoint);
            break;
        case Qt::MiddleButton:
            m_drawWidget->transform().addTranslation(newMousePoint - m_previousFrameMousePoint);
            break;
    }
    draw();
    m_previousFrameMousePoint = newMousePoint;
}

void controller::Controller::wheelEvent(QWheelEvent* event, const QPointF& mousePosition) {
    m_drawWidget->transform().addToScaleParameter(event->angleDelta().y() / 100);
    const auto mouseInWorld = m_coordinateConverter->screenToWorld(mousePosition);
    m_drawWidget->transform().setTranslation(mousePosition - m_drawWidget->transform().scale() * mouseInWorld);
    draw();
}

model::Model* controller::Controller::model() {
    return m_model;
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
                PRIMITIVE_TYPE::POINT); // Also sends signal
            break;
        case Qt::Key_L:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(PRIMITIVE_TYPE::LINE); // Also sends signal
            break;
        case Qt::Key_C:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                PRIMITIVE_TYPE::CIRCLE); // Also sends signal
            break;
        case Qt::Key_Y:
            m_leftSideBar->m_mousePointerTypeSelectWidget->setSelectedButton(
                PRIMITIVE_TYPE::POLY_LINE); // Also sends signal
            break;
        case Qt::Key_Escape:
            m_model->drawableHandler().stopStreaming();
            m_model->drawableHandler().clearSelectedAndHighlighted();
            draw();
            break;
        case Qt::Key_Delete: {
            m_model->deleteSelected();
            m_rightSideBar->clearWidget();
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

void controller::Controller::leftClickEvent(QMouseEvent* event) {
    if (m_modifierState.controlPressed()) {
        const auto leftClickedMousePosition = event->localPos();
        Drawable*  newlySelectedDrawable;
        if (m_modifierState.shiftPressed()) {
            newlySelectedDrawable = m_model->addToSelected(leftClickedMousePosition);
        } else {
            newlySelectedDrawable = m_model->selectNew(leftClickedMousePosition);
        }
        if (newlySelectedDrawable != nullptr) {
            setEditWidget(
                view::DrawableEditWidgetFactory::create(newlySelectedDrawable->type(), newlySelectedDrawable, this));
            draw();
        }
        if (m_model->drawableHandler().selectedDrawables().empty()) {
            m_rightSideBar->clearWidget();
        }
    } else {
        const auto leftClickedMousePosition = m_coordinateConverter->snapScreen(event->localPos(), 30);
        m_model->setPoint(m_coordinateConverter->screenToWorld(leftClickedMousePosition), m_modifierState);
        m_rightSideBar->clearWidget();
    }
}

void controller::Controller::rightClickEvent(QMouseEvent* event) {
    m_rightClickedMousePosition = event->localPos();
    if (m_model->drawableHandler().isStreaming()) {
        m_model->drawableHandler().addPointToStreamDrawable(
            m_coordinateConverter->screenToWorldSnap(m_rightClickedMousePosition, 30), true);
        addAction(new controller::ShowPrimitiveAction(m_model->drawableHandler().drawables().back()->index()), true);
    }
    m_selectedControlPoint = m_model->drawableHandler().getClosestControlPoint(
        m_coordinateConverter->screenToWorld(event->localPos()), 40 / m_drawWidget->transform().scale());
}

void controller::Controller::updateControlPoints() {
    m_model->drawableHandler().updateControlPoints();
}

void controller::Controller::setSelectedControlPoint(ControlPoint* selectedControlPoint) {
    m_selectedControlPoint = selectedControlPoint;
}

void controller::Controller::rightMouseMoveEvent(const QPointF& newMousePosition) {
    if (m_selectedControlPoint != nullptr) {
        m_selectedControlPoint->translate((newMousePosition - m_previousFrameMousePoint) /
                                          m_drawWidget->transform().scale());
        emit updateRightSideBar();
    } else if (not m_model->drawableHandler().selectedDrawables().empty()) {
        m_model->drawableHandler().translateSelected((newMousePosition - m_previousFrameMousePoint) /
                                                     m_drawWidget->transform().scale());
    } else if (m_model->drawableHandler().highlightedDrawable()) {
        m_model->drawableHandler().translateHighlighted((newMousePosition - m_previousFrameMousePoint) /
                                                        m_drawWidget->transform().scale());
    }
    updateControlPoints();
}

const controller::CoordinateConverter& controller::Controller::coordinateConverter() const {
    return *m_coordinateConverter;
}
