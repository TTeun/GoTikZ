//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "Action.h"
#include "UndoableAction.h"
#include "View/Widgets/LeftSideBar.h"

#include <QObject>
#include <QPointF>
#include <memory>
#include <stack>

class MainWindow;
class Model;
class QWheelEvent;
class GroupBoxContainer;
class QMouseEvent;
class QKeyEvent;

namespace View {
    class LeftSideBar;
    class MainWidget;
    class DrawWidget;
    class RightSideBar;
} // namespace View

namespace Controller {
    class ActionHandler : public QObject {
        Q_OBJECT

      public:
        explicit ActionHandler(MainWindow* mainWindow);
        ~ActionHandler() override = default;

        void              init(View::MainWidget* mainWidget, Model* model);
        void              undoAction();
        void              redoAction();
        Model*            model();
        View::DrawWidget* drawWidget();

        void draw();
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void wheelEvent(QWheelEvent* event, const QPointF& mousePosition);
        void keyPressEvent(QKeyEvent* event);
        void keyPressEventNoModifier(QKeyEvent* event);
        void keyPressEventWithCtrl(QKeyEvent* event);

        void setEditWidget(QWidget* widget);

      public slots:
        void addAction(UndoableAction* action, bool isAlreadyDone);
        void doAction(Action* action);

      signals:
        void updateRightSideBar();

      private:
        std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
        std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

        View::DrawWidget*   m_drawWidget{};
        View::LeftSideBar*  m_leftSideBar{};
        View::RightSideBar* m_rightSideBar{};
        MainWindow*         m_mainWindow;
        Model*              m_model{};

        QPointF m_previousMousePoint;
    };
} // namespace Controller

#endif // GOTIKZ_ACTIONHANDLER_H
