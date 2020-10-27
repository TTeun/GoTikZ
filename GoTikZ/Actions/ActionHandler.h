//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "UndoableAction.h"

#include <QObject>
#include <memory>
#include <stack>

class DrawWidget;
class LeftSideBar;
class RightSideBar;
class MainWindow;
class Model;
class GroupBoxContainer;
class QMouseEvent;
class QKeyEvent;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    ActionHandler(MainWindow* mainWindow);
    ~ActionHandler() = default;

    void        init(DrawWidget* drawWidget, LeftSideBar* leftSideBar, RightSideBar* rightSideBar, Model* model);
    void        undoAction();
    void        redoAction();
    DrawWidget* drawWidget();
    Model*      model();

    void draw();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);

    void setEditWidget(GroupBoxContainer* widget);

  public slots:
    void addAction(UndoableAction* action, bool isAlreadyDone);

    void doAction(Action* action);

  private:
    std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
    std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

    DrawWidget*   m_drawWidget;
    LeftSideBar*  m_leftSideBar;
    RightSideBar* m_rightSideBar;
    MainWindow*   m_mainWindow;
    Model*        m_model;
};

#endif // GOTIKZ_ACTIONHANDLER_H
