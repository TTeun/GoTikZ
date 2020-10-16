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
    layout->addWidget(m_primitiveSelectionWidget);
    setLayout(layout);

    buildViewGroupBox();
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

void LeftSideBar::buildViewGroupBox() {
    auto* groupBox       = new QGroupBox(this);
    auto* groupBoxLayout = new QVBoxLayout(groupBox);
    groupBox->setLayout(groupBoxLayout);
    groupBox->setTitle("View");

    auto* radioButton = new QRadioButton(groupBox);
    m_gridButton      = radioButton;
    radioButton->setChecked(true);
    radioButton->setText("Grid");

    auto* spinBox = new QSpinBox();
    spinBox->setValue(10);
    m_gridSpacingSpinBox = spinBox;

    groupBoxLayout->addWidget(radioButton);
    groupBoxLayout->addWidget(spinBox);

    groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout()->addWidget(groupBox);
}
