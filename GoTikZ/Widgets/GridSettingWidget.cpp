//
// Created by pc on 16-10-20.
//

#include "GridSettingWidget.h"

#include <QDebug>
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
    QObject::connect(m_showGridCheckBox, &QCheckBox::toggled, this, &GridSettingWidget::setShowGrid);
    groupBoxLayout->addWidget(m_showGridCheckBox);

    m_gridSpacingSpinBox = new QSpinBox(this);
    m_gridSpacingSpinBox->setValue(10);
    QObject::connect(m_gridSpacingSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &GridSettingWidget::setSpacing);
    groupBoxLayout->addWidget(m_gridSpacingSpinBox);

    groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(groupBox);
    setLayout(layout);
}
void GridSettingWidget::setSpacing(int spacing) {
    assert(spacing >= 0);
    m_gridState.setGridSpacing(spacing);
    emit actionDone(new ChangeGridAction(m_gridState));
}

void GridSettingWidget::setShowGrid(bool show) {
    m_gridState.setShowGrid(show);
    emit actionDone(new ChangeGridAction(m_gridState));
}
