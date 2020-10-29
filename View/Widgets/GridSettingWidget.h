//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_GRIDSETTINGWIDGET_H
#define GOTIKZ_GRIDSETTINGWIDGET_H

#include "View/GridState.h"
#include "View/Widgets/ActionWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

class QSpinBox;
class QCheckBox;

namespace view {
    class GridSettingWidget : public view::ActionWidget, public GroupBoxContainer {

      public:
        explicit GridSettingWidget(QWidget* parent);

      private:
        void setSpacing(int spacing);
        void setShowGrid(bool show);

        QSpinBox*  m_gridSpacingSpinBox;
        QCheckBox* m_showGridCheckBox;
        GridState  m_gridState;
    };
} // namespace view

#endif // GOTIKZ_GRIDSETTINGWIDGET_H
