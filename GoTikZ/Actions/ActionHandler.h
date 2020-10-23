//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "UndoableAction.h"

#include <QtCore/QObject>
#include <Widgets/PrimitiveSelectWidget.h>
#include <memory>
#include <stack>

class DrawWidget;
class LeftSideBar;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    ActionHandler(DrawWidget* drawWidget, LeftSideBar* leftSideBar);
    ~ActionHandler() = default;

    void                   init();
    void                   undoAction();
    void                   redoAction();
    DrawWidget*            drawWidget();
    PrimitiveSelectWidget* primitiveTypeSelectWidget();

  public slots:
    void addAction(UndoableAction* action, bool isAlreadyDone);

    void doAction(Action* action);

  private:
    std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
    std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

    DrawWidget*  m_drawWidget;
    LeftSideBar* m_leftSideBar;
};

#endif // GOTIKZ_ACTIONHANDLER_H
