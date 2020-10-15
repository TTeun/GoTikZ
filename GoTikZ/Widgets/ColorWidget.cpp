//
// Created by pc on 15-10-20.
//

#include "ColorWidget.h"

#include <QDebug>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QVBoxLayout>

ColorWidget::ColorWidget(QWidget *parent) : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  auto *pushButton = new QPushButton();
  m_pushButton = pushButton;
  m_pushButton->setStyleSheet("background-color: rgb(0,0,0);");

  layout->addWidget(pushButton);
  connect(pushButton, &QPushButton::clicked, this, &ColorWidget::getColor);
  setLayout(layout);
}

void ColorWidget::getColor() {
  m_color = QColorDialog::getColor();
  QString style = "background-color: rgb(" + QString::number(m_color.red()) +
                  "," + QString::number(m_color.green()) + "," +
                  QString::number(m_color.blue()) + ");";
  m_pushButton->setStyleSheet(style);
  emit colorUpdated(m_color);
}
