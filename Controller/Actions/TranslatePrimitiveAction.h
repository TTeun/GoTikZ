//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_TRANSLATEPRIMITIVEACTION_H
#define GOTIKZ_TRANSLATEPRIMITIVEACTION_H

#include "Controller/Actions/UndoableAction.h"

#include <QPointF>
#include <vector>

namespace Controller {

    class TranslatePrimitiveAction : public UndoableAction {
      public:
        TranslatePrimitiveAction(std::vector<size_t> mIndices, const QPointF& mTranslation);

        void doAction(ActionHandler* actionHandler) override;

        void undoAction(ActionHandler* actionHandler) override;

      private:
        std::vector<size_t> m_indices;
        const QPointF       m_translation;
    };
} // namespace Controller

#endif // GOTIKZ_TRANSLATEPRIMITIVEACTION_H
