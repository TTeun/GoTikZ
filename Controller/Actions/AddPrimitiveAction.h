//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_ADDPRIMITIVEACTION_H
#define GOTIKZ_ADDPRIMITIVEACTION_H

#include "Drawable/Drawable.h"
#include "UndoableAction.h"

namespace controller {
    class Controller;

    class AddPrimitiveAction : public UndoableAction {

      public:
        explicit AddPrimitiveAction(size_t indexOfPrimitive);

        void doAction(Controller* controller) override;

        void undoAction(Controller* controller) override;

      private:
        const size_t              m_indexOfPrimitive;
        std::unique_ptr<Drawable> m_drawable;
    };
} // namespace controller

#endif // GOTIKZ_ADDPRIMITIVEACTION_H
