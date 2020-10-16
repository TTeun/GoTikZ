//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ADDPRIMITIVEACTION_H
#define GOTIKZ_ADDPRIMITIVEACTION_H

#include "Action.h"
#include "Drawable/Drawable.h"

class ActionHandler;

class AddPrimitiveAction : public Action {

  public:
    AddPrimitiveAction(size_t indexOfPrimitive);

    void redoAction(ActionHandler* actionHandler) override;

    void undoAction(ActionHandler* actionHandler) override;

  protected:
    QString toString() override;

  private:
    const size_t              m_indexOfPrimitive;
    std::unique_ptr<Drawable> m_drawable;
};

#endif // GOTIKZ_ADDPRIMITIVEACTION_H
