//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "UndoableAction.h"

#include <QMouseEvent>
#include <QObject>
#include <memory>
#include <stack>

class DrawWidget;
class LeftSideBar;
class MainWindow;
class Model;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    ActionHandler(MainWindow* mainWindow);
    ~ActionHandler() = default;

    void        init(DrawWidget* drawWidget, LeftSideBar* leftSideBar, Model* model);
    void        undoAction();
    void        redoAction();
    DrawWidget* drawWidget();
    Model* model();

    void draw();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

  public slots:
    void addAction(UndoableAction* action, bool isAlreadyDone);

    void doAction(Action* action);

  private:
    std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
    std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

    DrawWidget*  m_drawWidget;
    MainWindow*  m_mainWindow;
    Model*       m_model;
};

#endif // GOTIKZ_ACTIONHANDLER_H
