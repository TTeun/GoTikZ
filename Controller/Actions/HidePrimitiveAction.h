//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_HIDEPRIMITIVEACTION_H
#define GOTIKZ_HIDEPRIMITIVEACTION_H

#include "Drawable/Drawable.h"
#include "UndoableAction.h"

#include <vector>

namespace controller {
    class Controller;

    class HidePrimitiveAction : public UndoableAction {

      public:
        explicit HidePrimitiveAction(std::vector<size_t> indices);

        void doAction(Controller* controller) override;
        void undoAction(Controller* controller) override;

      private:
        const std::vector<size_t> m_indices;
        //        std::vector<std::unique_ptr<Drawable>> m_drawables;
    };
} // namespace controller

#endif // GOTIKZ_HIDEPRIMITIVEACTION_H
