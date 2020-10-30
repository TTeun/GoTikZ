//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_TRANSLATEPRIMITIVEACTION_H
#define GOTIKZ_TRANSLATEPRIMITIVEACTION_H

#include "Controller/Actions/UndoableAction.h"

#include <QPointF>
#include <vector>

namespace controller {

    class TranslatePrimitiveAction : public UndoableAction {
      public:
        TranslatePrimitiveAction(std::vector<size_t> mIndices, const QPointF& mTranslation);

        void doAction(Controller* controller) override;

        void undoAction(Controller* controller) override;

      private:
        std::vector<size_t> m_indices;
        const QPointF       m_translation;
    };
} // namespace controller

#endif // GOTIKZ_TRANSLATEPRIMITIVEACTION_H
