//
// Created by pc on 27-10-20.
//

#include "LineEditWidget.h"

#include "Drawable/Line.h"
#include "DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/XyWidget.h"
#include "View/Widgets/PenWidget.h"

#include <QGroupBox>
#include <QLayout>

LineEditWidget::LineEditWidget(Line* line, controller::Controller* actionHandler)
    : view::DrawableEditWidget(nullptr), GroupBoxContainer(nullptr, "Line"), m_line(line), m_actionHandler(actionHandler) {
    auto* contentsLayout = m_groupBox->layout();

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(m_groupBox);

    m_point1Widget = new view::XyWidget(m_line->point1(), "p1");
    QObject::connect(m_point1Widget, &view::XyWidget::sendValues, this, &LineEditWidget::setPoint1);

    m_point2Widget = new view::XyWidget(m_line->point2(), "p2");
    QObject::connect(m_point2Widget, &view::XyWidget::sendValues, this, &LineEditWidget::setPoint2);

    contentsLayout->addWidget(m_point1Widget);
    contentsLayout->addWidget(m_point2Widget);

    auto* penWidget = new view::PenWidget(nullptr, line->index(), m_line->pen());
    QObject::connect(penWidget, &view::PenWidget::actionDone, m_actionHandler, &controller::Controller::doAction);
    contentsLayout->addWidget(penWidget);
}

void LineEditWidget::setPoint1(QPointF newPoint) {
    m_line->setPoint1(newPoint);
    m_actionHandler->draw();
}

void LineEditWidget::setPoint2(QPointF newPoint) {
    m_line->setPoint2(newPoint);
    m_actionHandler->draw();
}

void LineEditWidget::needsUpdate() {
    m_point1Widget->blockSignals(true);
    m_point1Widget->setValues(m_line->point1());
    m_point1Widget->blockSignals(false);

    m_point2Widget->blockSignals(true);
    m_point2Widget->setValues(m_line->point2());
    m_point2Widget->blockSignals(false);
}
