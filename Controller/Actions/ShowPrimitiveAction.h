//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_SHOWPRIMITIVEACTION_H
#define GOTIKZ_SHOWPRIMITIVEACTION_H

#include "Drawable/Drawable.h"
#include "UndoableAction.h"

namespace controller {
    class Controller;

    class ShowPrimitiveAction : public UndoableAction {

      public:
        explicit ShowPrimitiveAction(size_t indexOfPrimitive);

        void doAction(Controller* controller) override;
        void undoAction(Controller* controller) override;

      private:
        const size_t m_indexOfPrimitive;
    };
} // namespace controller

#endif // GOTIKZ_SHOWPRIMITIVEACTION_H
