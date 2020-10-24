//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_GRIDSETTINGWIDGET_H
#define GOTIKZ_GRIDSETTINGWIDGET_H

#include "../Actions/ChangeGridAction.h"
#include "ActionWidget.h"
#include "GroupBoxWidget.h"
#include "States/GridState.h"

class QSpinBox;
class QCheckBox;

class GridSettingWidget : public ActionWidget, public GroupBoxWidget {

  public:
    explicit GridSettingWidget(QWidget* parent = 0);

  private:
    void setSpacing(int spacing);
    void setShowGrid(bool show);

    QSpinBox*  m_gridSpacingSpinBox;
    QCheckBox* m_showGridCheckBox;
    GridState  m_gridState;
};

#endif // GOTIKZ_GRIDSETTINGWIDGET_H
