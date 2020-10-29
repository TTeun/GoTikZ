//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_DELETEPRIMITIVEACTION_H
#define GOTIKZ_DELETEPRIMITIVEACTION_H

#include "Drawable/Drawable.h"
#include "UndoableAction.h"

namespace controller {
    class Controller;
    class DeletePrimitiveAction : public UndoableAction {

      public:
        explicit DeletePrimitiveAction(size_t indexOfPrimitive);

        void doAction(Controller* actionHandler) override;
        void undoAction(Controller* actionHandler) override;

      private:
        const size_t              m_indexOfPrimitive;
        std::unique_ptr<Drawable> m_drawable;
    };
} // namespace controller

#endif // GOTIKZ_DELETEPRIMITIVEACTION_H
