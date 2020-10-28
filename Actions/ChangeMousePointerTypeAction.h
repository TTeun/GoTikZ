//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
#define GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H

#include "Model/MousePointerTypeEnum.h"
#include "Action.h"

class ChangeMousePointerTypeAction : public Action {

  public:
    explicit ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE newPrimitive);
    void doAction(ActionHandler* actionHandler) override;

  private:
    const MOUSE_POINTER_TYPE m_newPrimitive;
};

#endif // GOTIKZ_CHANGEMOUSEPOINTERTYPEACTION_H
