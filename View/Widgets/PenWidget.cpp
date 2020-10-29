//
// Created by pc on 23-10-20.
//

#include "PenWidget.h"

#include "ColorWidget.h"
#include "Controller/Actions/PenChangeAction.h"

#include <QGroupBox>
#include <QLayout>
#include <QSpinBox>

view::PenWidget::PenWidget(QWidget* parent) : GroupBoxContainer(parent, "Pen") {
    create();
}

view::PenWidget::PenWidget(QWidget* parent, size_t indexOfPrimitive, const QPen& pen)
    : GroupBoxContainer(parent, "Pen"), m_indexOfPrimitive(indexOfPrimitive), m_pen(pen) {
    create();
}

void view::PenWidget::create() {
    setLayout(new QHBoxLayout(this));
    m_pen.setJoinStyle(Qt::RoundJoin);
    auto* contentsLayout = m_groupBox->layout();

    auto* colorWidget = new view::ColorWidget(this, m_pen.color());
    QObject::connect(colorWidget, &view::ColorWidget::colorUpdated, this, &PenWidget::setColor);
    contentsLayout->addWidget(colorWidget);

    auto* spinBox = new QSpinBox(this);
    spinBox->setValue(m_pen.width());
    spinBox->setMinimum(1);
    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &PenWidget::setWidth);
    contentsLayout->addWidget(spinBox);
    layout()->addWidget(m_groupBox);
}

void view::PenWidget::setColor(const QColor& color) {
    m_pen.setColor(color);
    emit actionDone(new controller::PenChangeAction(m_pen, m_indexOfPrimitive));
}

void view::PenWidget::setWidth(int width) {
    assert(width > 0);
    m_pen.setWidth(width);
    emit actionDone(new controller::PenChangeAction(m_pen, m_indexOfPrimitive));
}
