//
// Created by pc on 16-10-20.
//

#include "GridSettingWidget.h"

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>

GridSettingWidget::GridSettingWidget(QWidget* parent) : ActionWidget(parent) {
    auto* layout         = new QVBoxLayout(this);
    auto* groupBox       = new QGroupBox(this);
    auto* groupBoxLayout = new QVBoxLayout(groupBox);
    groupBox->setLayout(groupBoxLayout);
    groupBox->setTitle("Grid");

    m_showGridCheckBox = new QCheckBox(this);
    m_showGridCheckBox->setChecked(true);
    m_showGridCheckBox->setText("Show");
    groupBoxLayout->addWidget(m_showGridCheckBox);

    m_gridSpacingSpinBox = new QSpinBox(this);
    m_gridSpacingSpinBox->setValue(10);
    groupBoxLayout->addWidget(m_gridSpacingSpinBox);

    groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(groupBox);
    setLayout(layout);
}
