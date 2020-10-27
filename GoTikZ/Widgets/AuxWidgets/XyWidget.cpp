//
// Created by pc on 27-10-20.
//

#include "XyWidget.h"

#include <QLabel>
#include <QVBoxLayout>

XyWidget::XyWidget(const QPointF& point, const QString& value) {
    auto* layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    m_xButton = new QSpinBox(this);
    m_yButton = new QSpinBox(this);

    QObject::connect(m_xButton, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &XyWidget::valuesChanged);
    QObject::connect(m_yButton, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &XyWidget::valuesChanged);

    m_xButton->setButtonSymbols(QAbstractSpinBox::NoButtons);
    m_yButton->setButtonSymbols(QAbstractSpinBox::NoButtons);

    m_xButton->setMaximumWidth(45);
    m_yButton->setMaximumWidth(45);

    m_xButton->setMaximumHeight(25);
    m_yButton->setMaximumHeight(25);

    m_xButton->setMaximum(std::numeric_limits<int>::max());
    m_yButton->setMaximum(std::numeric_limits<int>::max());

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
    const int x = m_xButton->value();
    const int y = m_yButton->value();
    emit      sendValues(QPointF(x, y));
}
