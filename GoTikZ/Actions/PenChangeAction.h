//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_PENCHANGEACTION_H
#define GOTIKZ_PENCHANGEACTION_H

#include "Action.h"

#include <QtGui/QPen>

class PenChangeAction : public Action {
  public:
    PenChangeAction(const QPen& pen, size_t indexOfPrimitive);

    void    doAction(ActionHandler* actionHandler) override;
    QString toString() override;

  private:
    QPen   m_pen;
    size_t m_indexOfPrimitive;
};

#endif // GOTIKZ_PENCHANGEACTION_H
