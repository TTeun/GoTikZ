//
// Created by pc on 23-10-20.
//

#include "PenWidget.h"

#include "../Actions/PenChangeAction.h"
#include "ColorWidget.h"

#include <QGroupBox>
#include <QLayout>
#include <QSpinBox>

PenWidget::PenWidget(QWidget* parent) : GroupBoxContainer(parent, "Pen") {
    create();
}

PenWidget::PenWidget(size_t indexOfPrimitive, QWidget* parent)
    : GroupBoxContainer(parent, "Pen"), m_indexOfPrimitive(indexOfPrimitive) {
    create();
}

void PenWidget::create() {
    auto* contentsLayout = layout();

    auto* colorWidget = new ColorWidget(groupBox());
    QObject::connect(colorWidget, &ColorWidget::colorUpdated, this, &PenWidget::setColor);
    contentsLayout->addWidget(colorWidget);

    auto* spinBox = new QSpinBox(groupBox());
    spinBox->setValue(3);
    spinBox->setMinimum(1);
    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &PenWidget::setWidth);
    contentsLayout->addWidget(spinBox);
}

void PenWidget::setColor(QColor color) {
    m_pen.setColor(color);
    emit actionDone(new PenChangeAction(m_pen, m_indexOfPrimitive));
}

void PenWidget::setWidth(int width) {
    assert(width > 0);
    m_pen.setWidth(width);
    emit actionDone(new PenChangeAction(m_pen, m_indexOfPrimitive));
}
