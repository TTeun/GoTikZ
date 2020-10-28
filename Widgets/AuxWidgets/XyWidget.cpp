//
// Created by pc on 27-10-20.
//

#include "XyWidget.h"

#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>

XyWidget::XyWidget(const QPointF& point, const QString& value) {
    auto* layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    m_xButton = new QDoubleSpinBox(this);
    m_xButton->setObjectName("xButton");
    m_yButton = new QDoubleSpinBox(this);
    m_yButton->setObjectName("yButton");

    QObject::connect(m_xButton, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,
                     &XyWidget::valuesChanged);
    QObject::connect(m_yButton, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,
                     &XyWidget::valuesChanged);

    m_xButton->setButtonSymbols(QAbstractSpinBox::NoButtons);
    m_yButton->setButtonSymbols(QAbstractSpinBox::NoButtons);

    m_xButton->setMaximumWidth(45);
    m_yButton->setMaximumWidth(45);

    m_xButton->setMaximumHeight(25);
    m_yButton->setMaximumHeight(25);

    m_xButton->setMaximum(std::numeric_limits<int>::max());
    m_yButton->setMaximum(std::numeric_limits<int>::max());
    m_xButton->setMinimum(std::numeric_limits<int>::min());
    m_yButton->setMinimum(std::numeric_limits<int>::min());

    m_xButton->setValue(point.x());
    m_yButton->setValue(point.y());

    layout->addWidget(new QLabel(value + "=("));
    layout->addWidget(m_xButton);
    layout->addWidget(new QLabel(","));
    layout->addWidget(m_yButton);
    layout->addWidget(new QLabel(")"));
    setLayout(layout);
}

void XyWidget::valuesChanged(int dummy) {
    const double x = m_xButton->value();
    const double y = m_yButton->value();
    emit         sendValues(QPointF(x, y));
}

void XyWidget::setValues(const QPointF& values) {
    m_xButton->blockSignals(true);
    m_yButton->blockSignals(true);
    m_xButton->setValue(values.x());
    m_yButton->setValue(values.y());
    m_xButton->blockSignals(false);
    m_yButton->blockSignals(false);
}
