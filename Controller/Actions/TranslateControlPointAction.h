//
// Created by pc on 31-10-20.
//

#ifndef GOTIKZ_TRANSLATECONTROLPOINTACTION_H
#define GOTIKZ_TRANSLATECONTROLPOINTACTION_H

#include "Controller/Actions/UndoableAction.h"

#include <QPointF>
#include <vector>

namespace controller {

    class TranslateControlPointAction : public UndoableAction {
      public:
        TranslateControlPointAction(size_t index, const QPointF& translation);

        void doAction(Controller* controller) override;
        void undoAction(Controller* controller) override;

      private:
        const size_t  m_index;
        const QPointF m_translation;
    };
} // namespace controller

#endif // GOTIKZ_TRANSLATECONTROLPOINTACTION_H
