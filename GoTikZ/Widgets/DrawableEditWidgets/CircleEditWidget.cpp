//
// Created by pc on 27-10-20.
//

#include "CircleEditWidget.h"

#include "../Drawable/Circle.h"
#include "Actions/ActionHandler.h"

#include <QLayout>
#include <Widgets/AuxWidgets/XyWidget.h>

CircleEditWidget::CircleEditWidget(Circle* circle, ActionHandler* actionHandler)
    : GroupBoxContainer(nullptr, "Circle"), m_actionHandler(actionHandler), m_circle(circle) {
    auto* contentsLayout = layout();
    auto* centerWidget   = new XyWidget(circle->center(), "Center");
    QObject::connect(centerWidget, &XyWidget::sendValues, this, &CircleEditWidget::setCenter);

    contentsLayout->addWidget(centerWidget);

    auto* radiusSpinBox = new QSpinBox();
    radiusSpinBox->setMaximum(std::numeric_limits<int>::max());
    radiusSpinBox->setValue(circle->radius());

    QObject::connect(radiusSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &CircleEditWidget::setRadius);
    contentsLayout->addWidget(radiusSpinBox);
}

void CircleEditWidget::setCenter(QPointF newCenter) {
    m_circle->setCenter(newCenter);
    m_actionHandler->draw();
}

void CircleEditWidget::setRadius(double newCenter) {
    m_circle->setRadius(newCenter);
    m_actionHandler->draw();
}
