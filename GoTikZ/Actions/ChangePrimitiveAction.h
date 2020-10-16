//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_CHANGEPRIMITIVEACTION_H
#define GOTIKZ_CHANGEPRIMITIVEACTION_H

#include "Action.h"

#include <Widgets/DrawWidget.h>

class ChangePrimitiveAction : public Action {

  public:
    ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE newPrimitive);

    void redoAction(ActionHandler* actionHandler) override;
    void undoAction(ActionHandler* actionHandler) override;

    QString toString() override;

  private:
    const DrawWidget::PRIMITIVE_TYPE m_newPrimitive;
};

#endif // GOTIKZ_CHANGEPRIMITIVEACTION_H
