//
// Created by pc on 15-10-20.
//

#include "ColorWidget.h"

#include <QColorDialog>
#include <QPushButton>
#include <QVBoxLayout>

ColorWidget::ColorWidget(QWidget* parent, const QColor& color) : QWidget(parent) {
    auto* layout     = new QVBoxLayout(this);
    auto* pushButton = new QPushButton();
    m_pushButton     = pushButton;
    QString style    = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) +
                    "," + QString::number(color.blue()) + ");";
    m_pushButton->setStyleSheet(style);

    layout->addWidget(pushButton);
    connect(pushButton, &QPushButton::clicked, this, &ColorWidget::getColor);
    setLayout(layout);
}

void ColorWidget::getColor() {
    m_color       = QColorDialog::getColor(m_color);
    QString style = "background-color: rgb(" + QString::number(m_color.red()) + "," + QString::number(m_color.green()) +
                    "," + QString::number(m_color.blue()) + ");";
    m_pushButton->setStyleSheet(style);
    emit colorUpdated(m_color);
}
