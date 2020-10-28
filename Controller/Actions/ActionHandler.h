//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "UndoableAction.h"

#include <QObject>
#include <QPointF>
#include <memory>
#include <stack>

class DrawWidget;
class LeftSideBar;
class RightSideBar;
class MainWindow;
class Model;
class QWheelEvent;
class GroupBoxContainer;
class QMouseEvent;
class QKeyEvent;
class MainWidget;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    explicit ActionHandler(MainWindow* mainWindow);
    ~ActionHandler() override = default;

    void        init(MainWidget* mainWidget, Model* model);
    void        undoAction();
    void        redoAction();
    DrawWidget* drawWidget();
    Model*      model();

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

    DrawWidget*   m_drawWidget{};
    LeftSideBar*  m_leftSideBar{};
    RightSideBar* m_rightSideBar{};
    MainWindow*   m_mainWindow;
    Model*        m_model{};

    QPointF m_previousMousePoint;
};

#endif // GOTIKZ_ACTIONHANDLER_H
