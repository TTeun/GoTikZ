//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_GRIDSETTINGWIDGET_H
#define GOTIKZ_GRIDSETTINGWIDGET_H

#include "ActionWidget.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpinBox>
#include <States/GridState.h>

class GridSettingWidget : public ActionWidget {

  public:
    explicit GridSettingWidget(QWidget* parent = 0);

  private:
    QSpinBox*  m_gridSpacingSpinBox;
    QCheckBox* m_showGridCheckBox;
    GridState  m_gridState;
};

#endif // GOTIKZ_GRIDSETTINGWIDGET_H
