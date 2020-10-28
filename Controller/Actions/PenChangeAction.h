//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_PENCHANGEACTION_H
#define GOTIKZ_PENCHANGEACTION_H

#include "Action.h"
#include "ActionHandler.h"

#include <QPen>

class PenChangeAction : public Action {
  public:
    PenChangeAction(QPen  pen, size_t indexOfPrimitive);

    void doAction(Controller::ActionHandler* actionHandler) override;

  private:
    QPen   m_pen;
    size_t m_indexOfPrimitive;
};

#endif // GOTIKZ_PENCHANGEACTION_H
