//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONWIDGET_H
#define GOTIKZ_ACTIONWIDGET_H

#include "Controller/Actions/Action.h"

#include <QWidget>

namespace Controller {
    class UndoableAction;
    class Action;
} // namespace Controller

namespace View {
    class ActionWidget : public QWidget {
        Q_OBJECT

      protected:
        explicit ActionWidget() = default;

      signals:
        void undoableActionDone(Controller::UndoableAction* action, bool isAlreadyDone);
        void actionDone(Controller::Action* action);
    };
} // namespace View

#endif // GOTIKZ_ACTIONWIDGET_H
