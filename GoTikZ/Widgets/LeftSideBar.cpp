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

LeftSideBar::LeftSideBar(QWidget *parent) : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  setLayout(layout);
  buildViewGroupBox();
  buildPenGroupBox();
  buildTypeGroupBox();
}

void LeftSideBar::addTypeButton(QGroupBox *groupbox, QButtonGroup *buttonGroup,
                                const QString &title, bool selected) {
  auto *radioButton = new QRadioButton(groupbox);
  radioButton->setChecked(selected);
  radioButton->setText(title);
  buttonGroup->addButton(radioButton);
  groupbox->layout()->addWidget(radioButton);
}

void LeftSideBar::typeClicked(QAbstractButton *button) {
  if (button->text() == QString("Point")) {
    emit typeChanged(DrawWidget::DRAW_TYPE::POINT);
  } else if (button->text() == QString("Line")) {
    emit typeChanged(DrawWidget::DRAW_TYPE::LINE);
  } else if (button->text() == QString("Circle")) {
    emit typeChanged(DrawWidget::DRAW_TYPE::CIRCLE);
  } else if (button->text() == QString("PolyLine")) {
    emit typeChanged(DrawWidget::DRAW_TYPE::POLY_LINE);
  } else {
  }
}

void LeftSideBar::buildTypeGroupBox() {
  auto *groupBox = new QGroupBox(this);
  auto *groupBoxLayout = new QVBoxLayout(groupBox);
  groupBox->setLayout(groupBoxLayout);
  groupBox->setTitle("Type");

  auto *buttonGroup = new QButtonGroup(groupBox);

  addTypeButton(groupBox, buttonGroup, "Line", true);
  addTypeButton(groupBox, buttonGroup, "Circle", false);
  addTypeButton(groupBox, buttonGroup, "Point", false);
  addTypeButton(groupBox, buttonGroup, "PolyLine", false);

  connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton *)), this,
          SLOT(typeClicked(QAbstractButton *)));

  groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  layout()->addWidget(groupBox);
}

void LeftSideBar::buildPenGroupBox() {
  auto *groupBox = new QGroupBox(this);
  auto *groupBoxLayout = new QVBoxLayout(groupBox);
  groupBox->setLayout(groupBoxLayout);
  groupBox->setTitle("Pen");

  groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  auto *colorWidget = new ColorWidget(this);
  m_colorWidget = colorWidget;

  groupBoxLayout->addWidget(colorWidget);

  layout()->addWidget(groupBox);
}

void LeftSideBar::buildViewGroupBox() {
  auto *groupBox = new QGroupBox(this);
  auto *groupBoxLayout = new QVBoxLayout(groupBox);
  groupBox->setLayout(groupBoxLayout);
  groupBox->setTitle("View");

  auto *radioButton = new QRadioButton(groupBox);
  m_gridButton = radioButton;
  radioButton->setChecked(true);
  radioButton->setText("Grid");

  groupBoxLayout->addWidget(radioButton);
  groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  layout()->addWidget(groupBox);
}
