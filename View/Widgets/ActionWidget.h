//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONWIDGET_H
#define GOTIKZ_ACTIONWIDGET_H

#include <QWidget>

namespace controller {
    class UndoableAction;
    class Action;
} // namespace controller

namespace view {
    class ActionWidget : public QWidget {
        Q_OBJECT

      protected:
        explicit ActionWidget() = default;

      signals:
        void undoableActionDone(controller::UndoableAction* action, bool isAlreadyDone);
        void actionDone(controller::Action* action);
    };
} // namespace view

#endif // GOTIKZ_ACTIONWIDGET_H
