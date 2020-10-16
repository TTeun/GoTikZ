//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTION_H
#define GOTIKZ_ACTION_H

#include <QtCore/QString>

class ActionHandler;

class Action {
  public:
    enum class ACTION_TYPE { ADD_PRIMITIVE, CHANGE_PRIMITIVE_TYPE };

    Action(ACTION_TYPE type);
    ~Action() = default;

    virtual void redoAction(ActionHandler* actionHandler) = 0;
    virtual void undoAction(ActionHandler* actionHandler) = 0;

  public:
    virtual QString toString() = 0;

  protected:
    ACTION_TYPE m_actionType;
};

#endif // GOTIKZ_ACTION_H
