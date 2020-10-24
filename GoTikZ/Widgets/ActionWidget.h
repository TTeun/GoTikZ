//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONWIDGET_H
#define GOTIKZ_ACTIONWIDGET_H

#include <QObject>

class UndoableAction;
class Action;

class ActionWidget : public QObject {
    Q_OBJECT

  protected:
    explicit ActionWidget() = default;

  signals:
    void undoableActionDone(UndoableAction* action, bool isAlreadyDone);
    void actionDone(Action* action);
};

#endif // GOTIKZ_ACTIONWIDGET_H
