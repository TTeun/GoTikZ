//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_DELETEPRIMITIVEACTION_H
#define GOTIKZ_DELETEPRIMITIVEACTION_H

#include "ActionHandler.h"
#include "Drawable/Drawable.h"
#include "UndoableAction.h"

class ActionHandler;

class DeletePrimitiveAction : public UndoableAction {

  public:
    explicit DeletePrimitiveAction(size_t indexOfPrimitive);

    void doAction(Controller::ActionHandler* actionHandler) override;
    void undoAction(Controller::ActionHandler* actionHandler) override;

  private:
    const size_t              m_indexOfPrimitive;
    std::unique_ptr<Drawable> m_drawable;
};

#endif // GOTIKZ_DELETEPRIMITIVEACTION_H
