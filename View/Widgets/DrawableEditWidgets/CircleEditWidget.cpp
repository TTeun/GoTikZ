//
// Created by pc on 27-10-20.
//

#include "CircleEditWidget.h"

#include "Controller/Controller.h"
#include "Drawable/Circle.h"
#include "DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/XyWidget.h"
#include "View/Widgets/PenWidget.h"

#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QLayout>

view::CircleEditWidget::CircleEditWidget(Circle* circle, controller::Controller* controller)
    : DrawableEditWidget(nullptr), GroupBoxContainer(nullptr, "Circle"), m_controller(controller), m_circle(circle) {

    setLayout(new QHBoxLayout(this));
    auto* contentsLayout = m_groupBox->layout();
    m_centerWidget       = new view::XyWidget(circle->center(), "Center");
    m_centerWidget->setObjectName("centerWidget");
    QObject::connect(m_centerWidget, &view::XyWidget::sendValues, this, &CircleEditWidget::setCenter);

    contentsLayout->addWidget(m_centerWidget);

    m_radiusSpinBox = new QSpinBox(m_groupBox);
    m_radiusSpinBox->setObjectName("radiusSpinBox");
    m_radiusSpinBox->setMaximum(std::numeric_limits<int>::max());
    m_radiusSpinBox->setValue(circle->radius());

    QObject::connect(m_radiusSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &CircleEditWidget::setRadius);
    contentsLayout->addWidget(m_radiusSpinBox);

    auto* penWidget = new view::PenWidget(nullptr, circle->index(), m_circle->pen());
    QObject::connect(penWidget, &view::PenWidget::actionDone, m_controller, &controller::Controller::doAction);
    contentsLayout->addWidget(penWidget);
    layout()->addWidget(m_groupBox);
}

void view::CircleEditWidget::setCenter(QPointF newCenter) {
    m_circle->setCenter(newCenter);
    m_controller->updateControlPoints();
    m_controller->draw();
}

void view::CircleEditWidget::setRadius(double newCenter) {
    m_circle->setRadius(newCenter);
    m_controller->updateControlPoints();
    m_controller->draw();
}

void view::CircleEditWidget::needsUpdate() {
    m_radiusSpinBox->blockSignals(true);
    m_radiusSpinBox->setValue(m_circle->radius());
    m_radiusSpinBox->blockSignals(false);
    m_centerWidget->setValues(m_circle->center());
}
