//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_DELETEPRIMITIVEACTION_H
#define GOTIKZ_DELETEPRIMITIVEACTION_H

#include "ActionHandler.h"
#include "Drawable/Drawable.h"
#include "UndoableAction.h"

class ActionHandler;

namespace Controller {
    class DeletePrimitiveAction : public UndoableAction {

      public:
        explicit DeletePrimitiveAction(size_t indexOfPrimitive);

        void doAction(ActionHandler* actionHandler) override;
        void undoAction(ActionHandler* actionHandler) override;

      private:
        const size_t              m_indexOfPrimitive;
        std::unique_ptr<Drawable> m_drawable;
    };
} // namespace Controller

#endif // GOTIKZ_DELETEPRIMITIVEACTION_H
