//
// Created by pc on 27-10-20.
//

#include "PointEditWidget.h"

#include "Controller/Controller.h"
#include "Drawable/Point.h"
#include "DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/XyWidget.h"
#include "View/Widgets/PenWidget.h"

#include <QGroupBox>
#include <QLayout>

PointEditWidget::PointEditWidget(Point* point, controller::Controller* actionHandler)
    : DrawableEditWidget(nullptr), GroupBoxContainer(nullptr, "Point"), m_actionHandler(actionHandler), m_point(point) {
    auto* contentsLayout = m_groupBox->layout();

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(m_groupBox);

    m_point1Widget = new view::XyWidget(m_point->point(), "pt");
    QObject::connect(m_point1Widget, &view::XyWidget::sendValues, this, &PointEditWidget::setPoint);

    contentsLayout->addWidget(m_point1Widget);

    auto* penWidget = new view::PenWidget(nullptr, m_point->index(), m_point->pen());
    QObject::connect(penWidget, &view::PenWidget::actionDone, m_actionHandler, &controller::Controller::doAction);
    contentsLayout->addWidget(penWidget);
}

void PointEditWidget::setPoint(QPointF newPoint) {
    m_point->setPoint(newPoint);
    m_actionHandler->draw();
}

void PointEditWidget::needsUpdate() {
    m_point1Widget->blockSignals(true);
    m_point1Widget->setValues(m_point->point());
    m_point1Widget->blockSignals(false);
}
