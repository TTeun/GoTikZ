//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ACTION_H
#define GOTIKZ_ACTION_H

#include <QString>

class ActionHandler;

class Action {
  protected:
    enum class ACTION_TYPE { ADD_PRIMITIVE, CHANGE_PRIMITIVE_TYPE, CHANGE_GRID_STATE, CHANGE_PEN };

    explicit Action(ACTION_TYPE type);

  public:
    virtual void doAction(ActionHandler* actionHandler) = 0;

  protected:
    ACTION_TYPE m_actionType;
};

#endif // GOTIKZ_ACTION_H
