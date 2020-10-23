//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "ColorWidget.h"

#include <QButtonGroup>
#include <QGroupBox>
#include <QRadioButton>
#include <QStyle>
#include <QVBoxLayout>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

LeftSideBar::LeftSideBar(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    m_primitiveSelectionWidget = new PrimitiveSelectWidget(this);
    m_gridSettingWidget        = new GridSettingWidget(this);
    layout->addWidget(m_primitiveSelectionWidget);
    layout->addWidget(m_gridSettingWidget);
    setLayout(layout);

    //    buildViewGroupBox();
    buildPenGroupBox();
}

void LeftSideBar::buildPenGroupBox() {
    auto* groupBox       = new QGroupBox(this);
    auto* groupBoxLayout = new QVBoxLayout(groupBox);
    groupBox->setLayout(groupBoxLayout);
    groupBox->setTitle("Pen");

    groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    auto* colorWidget = new ColorWidget(this);
    m_colorWidget     = colorWidget;

    groupBoxLayout->addWidget(colorWidget);

    layout()->addWidget(groupBox);
}
