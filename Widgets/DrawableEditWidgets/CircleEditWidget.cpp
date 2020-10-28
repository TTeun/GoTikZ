//
// Created by pc on 27-10-20.
//

#include "CircleEditWidget.h"

#include "../../Drawable/Circle.h"
#include "Actions/ActionHandler.h"
#include "Widgets/AuxWidgets/XyWidget.h"
#include "Widgets/PenWidget.h"

#include <QGroupBox>
#include <QLayout>

CircleEditWidget::CircleEditWidget(Circle* circle, ActionHandler* actionHandler)
    : GroupBoxContainer(nullptr, "Circle"), m_actionHandler(actionHandler), m_circle(circle) {
    QObject::connect(m_actionHandler, &ActionHandler::updateRightSideBar, this, &CircleEditWidget::needsUpdate);

    setLayout(new QHBoxLayout(this));
    auto* contentsLayout = m_groupBox->layout();
    m_centerWidget       = new XyWidget(circle->center(), "Center");
    m_centerWidget->setObjectName("centerWidget");
    QObject::connect(m_centerWidget, &XyWidget::sendValues, this, &CircleEditWidget::setCenter);

    contentsLayout->addWidget(m_centerWidget);

    m_radiusSpinBox = new QSpinBox(m_groupBox);
    m_radiusSpinBox->setObjectName("radiusSpinBox");
    m_radiusSpinBox->setMaximum(std::numeric_limits<int>::max());
    m_radiusSpinBox->setValue(circle->radius());

    QObject::connect(m_radiusSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
                     &CircleEditWidget::setRadius);
    contentsLayout->addWidget(m_radiusSpinBox);

    auto* penWidget = new PenWidget(nullptr, circle->index(), m_circle->pen());
    QObject::connect(penWidget, &PenWidget::actionDone, m_actionHandler, &ActionHandler::doAction);
    contentsLayout->addWidget(penWidget);
    layout()->addWidget(m_groupBox);
}

void CircleEditWidget::setCenter(QPointF newCenter) {
    m_circle->setCenter(newCenter);
    m_actionHandler->draw();
}

void CircleEditWidget::setRadius(double newCenter) {
    m_circle->setRadius(newCenter);
    m_actionHandler->draw();
}

void CircleEditWidget::needsUpdate() {
    m_radiusSpinBox->blockSignals(true);
    m_radiusSpinBox->setValue(m_circle->radius());
    m_radiusSpinBox->blockSignals(false);
    m_centerWidget->setValues(m_circle->center());
}

CircleEditWidget::~CircleEditWidget() {
}
