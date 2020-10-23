//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONWIDGET_H
#define GOTIKZ_ACTIONWIDGET_H

#include <QWidget>

class UndoableAction;
class Action;

class ActionWidget : public QWidget {
    Q_OBJECT

  protected:
    explicit ActionWidget(QWidget* parent);

  signals:
    void undoableActionDone(UndoableAction* action, bool isAlreadyDone, bool canBeUndone);
    void actionDone(Action* action);
};

#endif // GOTIKZ_ACTIONWIDGET_H
