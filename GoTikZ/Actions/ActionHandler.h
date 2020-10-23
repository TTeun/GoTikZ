//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONHANDLER_H
#define GOTIKZ_ACTIONHANDLER_H

#include "UndoableAction.h"

#include <QtCore/QObject>
#include <memory>
#include <stack>

class DrawWidget;
class PrimitiveSelectWidget;

class ActionHandler : public QObject {
    Q_OBJECT

  public:
    ActionHandler(DrawWidget* drawWidget, PrimitiveSelectWidget* primitiveTypeSelectWidget);
    ~ActionHandler() = default;

    void                   undoAction();
    void                   redoAction();
    DrawWidget*            drawWidget();
    PrimitiveSelectWidget* primitiveTypeSelectWidget();

  public slots:
    void addAction(UndoableAction* action, bool isAlreadyDone, bool canBeUndone);

    void doAction(Action* action);

  private:
    std::stack<std::unique_ptr<UndoableAction>> m_undoStack;
    std::stack<std::unique_ptr<UndoableAction>> m_redoStack;

    DrawWidget*            m_drawWidget;
    PrimitiveSelectWidget* m_primitiveTypeSelectWidget;
};

#endif // GOTIKZ_ACTIONHANDLER_H
