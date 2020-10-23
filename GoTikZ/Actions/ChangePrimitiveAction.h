//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEPRIMITIVEACTION_H
#define GOTIKZ_CHANGEPRIMITIVEACTION_H

#include "UndoableAction.h"

#include <Widgets/DrawWidget.h>

class ChangePrimitiveAction : public Action {

  public:
    explicit ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE newPrimitive);
    void doAction(ActionHandler* actionHandler) override;

    QString toString() override;

  private:
    const DrawWidget::PRIMITIVE_TYPE m_newPrimitive;
};

#endif // GOTIKZ_CHANGEPRIMITIVEACTION_H
