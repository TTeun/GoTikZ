//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_GRIDSETTINGWIDGET_H
#define GOTIKZ_GRIDSETTINGWIDGET_H

#include "ActionWidget.h"
#include "GroupBoxContainer.h"
#include "States/GridState.h"

class QSpinBox;
class QCheckBox;

class GridSettingWidget : public ActionWidget, public GroupBoxContainer {

  public:
    explicit GridSettingWidget(QWidget* parent);

  private:
    void setSpacing(int spacing);
    void setShowGrid(bool show);

    QSpinBox*  m_gridSpacingSpinBox;
    QCheckBox* m_showGridCheckBox;
    GridState  m_gridState;
};

#endif // GOTIKZ_GRIDSETTINGWIDGET_H
