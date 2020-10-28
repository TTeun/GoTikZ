//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTIONWIDGET_H
#define GOTIKZ_ACTIONWIDGET_H

#include "Controller/Actions/Action.h"

#include <QWidget>

class UndoableAction;
class Action;

namespace View {
    class ActionWidget : public QWidget {
        Q_OBJECT

      protected:
        explicit ActionWidget() = default;

      signals:
        void undoableActionDone(UndoableAction* action, bool isAlreadyDone);
        void actionDone(Action* action);
    };
} // namespace View

#endif // GOTIKZ_ACTIONWIDGET_H
