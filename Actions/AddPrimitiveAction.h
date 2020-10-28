//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ADDPRIMITIVEACTION_H
#define GOTIKZ_ADDPRIMITIVEACTION_H

#include "Drawable/Drawable.h"
#include "UndoableAction.h"

class ActionHandler;

class AddPrimitiveAction : public UndoableAction {

  public:
    explicit AddPrimitiveAction(size_t indexOfPrimitive);

    void doAction(ActionHandler* actionHandler) override;

    void undoAction(ActionHandler* actionHandler) override;

  private:
    const size_t              m_indexOfPrimitive;
    std::unique_ptr<Drawable> m_drawable;
};

#endif // GOTIKZ_ADDPRIMITIVEACTION_H
