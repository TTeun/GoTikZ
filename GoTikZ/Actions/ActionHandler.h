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
class MainWindow;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    ActionHandler(MainWindow* mainWindow);
    ~ActionHandler() = default;

    void        init(DrawWidget* drawWidget, LeftSideBar* leftSideBar);
    void        undoAction();
    void        redoAction();
    DrawWidget* drawWidget();

        void draw();

  public slots:
    void addAction(UndoableAction* action, bool isAlreadyDone);

    void doAction(Action* action);

  private:
    std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
    std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

    DrawWidget*  m_drawWidget;
    MainWindow*  m_mainWindow;
    LeftSideBar* m_leftSideBar;
};

#endif // GOTIKZ_ACTIONHANDLER_H
