//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CONTROLLER_H
#define GOTIKZ_CONTROLLER_H

#include "Controller/Actions/UndoableAction.h"
#include "Controller/CoordinateConverter.h"
#include "Controller/ModifierState.h"
#include "CoordinateConverter.h"

#include <QObject>
#include <QPointF>
#include <memory>
#include <stack>

class MainWindow;
class QWheelEvent;
class QMouseEvent;
class QKeyEvent;
class ControlPoint;

namespace model {
    class Model;
}

namespace view {
    class LeftSideBar;
    class MainWidget;
    class DrawWidget;
    class RightSideBar;
} // namespace view

namespace controller {
    class Action;
    class Controller : public QObject {
        Q_OBJECT

      public:
        explicit Controller(MainWindow* mainWindow);
        ~Controller() override = default;

        void                       init(view::MainWidget* mainWidget, model::Model* model);
        void                       undoAction();
        void                       redoAction();
        void                       draw();
        void                       mousePressEvent(QMouseEvent* event);
        void                       leftClickEvent(QMouseEvent* event);
        void                       rightClickEvent(QMouseEvent* event);
        void                       rightMouseMoveEvent(const QPointF& newMousePosition);
        void                       mouseReleaseEvent(QMouseEvent* event);
        void                       mouseMoveEvent(QMouseEvent* event);
        void                       wheelEvent(QWheelEvent* event, const QPointF& mousePosition);
        void                       keyPressEvent(QKeyEvent* event);
        void                       keyReleaseEvent(QKeyEvent* event);
        void                       keyPressEventNoModifier(QKeyEvent* event);
        void                       keyPressEventWithControl(QKeyEvent* event);
        void                       keyPressEventWithControlAndShift(QKeyEvent* event);
        void                       setSelectedControlPoint(ControlPoint* selectedControlPoint);
        void                       setEditWidget(QWidget* widget);
        model::Model*              model();
        view::DrawWidget*          drawWidget();
        const CoordinateConverter& coordinateConverter() const;

      public slots:
        void addAction(UndoableAction* action, bool isAlreadyDone);
        void doAction(Action* action);
        void updateControlPoints();

      signals:
        void updateRightSideBar();

      private:
        std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
        std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

        view::DrawWidget*                                m_drawWidget;
        view::LeftSideBar*                               m_leftSideBar;
        view::RightSideBar*                              m_rightSideBar;
        MainWindow*                                      m_mainWindow;
        model::Model*                                    m_model;
        controller::ModifierState                        m_modifierState;
        QPointF                                          m_previousFrameMousePoint;
        QPointF                                          m_rightClickedMousePosition;
        ControlPoint*                                    m_selectedControlPoint;
        std::unique_ptr<controller::CoordinateConverter> m_coordinateConverter;
    };
} // namespace controller

#endif // GOTIKZ_CONTROLLER_H
