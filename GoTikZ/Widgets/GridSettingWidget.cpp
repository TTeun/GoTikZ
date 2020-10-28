//
// Created by pc on 16-10-20.
//

#include "GridSettingWidget.h"

#include "../Actions/ChangeGridAction.h"

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

GridSettingWidget::GridSettingWidget(QWidget* parent) : GroupBoxContainer(parent, "Grid") {
    auto* contentsLayout = layout();

    m_showGridCheckBox = new QCheckBox(groupBox());
    m_showGridCheckBox->setChecked(true);
    m_showGridCheckBox->setText("Grid");
    QObject::connect(m_showGridCheckBox, &QCheckBox::toggled, this, &GridSettingWidget::setShowGrid);
    contentsLayout->addWidget(m_showGridCheckBox);

    m_gridSpacingSpinBox = new QSpinBox(groupBox());
    m_gridSpacingSpinBox->setValue(m_gridState.gridSpacing());
    QObject::connect(m_gridSpacingSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &GridSettingWidget::setSpacing);
    contentsLayout->addWidget(m_gridSpacingSpinBox);
}

void GridSettingWidget::setSpacing(int spacing) {
    assert(spacing >= 0);
    m_gridState.setGridSpacing(static_cast<size_t>(spacing));
    emit actionDone(new ChangeGridAction(m_gridState));
}

void GridSettingWidget::setShowGrid(bool show) {
    m_gridState.setShowGrid(show);
    emit actionDone(new ChangeGridAction(m_gridState));
}
