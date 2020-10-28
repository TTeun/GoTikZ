//
// Created by pc on 27-10-20.
//

#include "PointEditWidget.h"

#include "../../Controller/Actions/ActionHandler.h"
#include "../../Drawable/Point.h"
#include "Widgets/AuxWidgets/XyWidget.h"
#include "Widgets/PenWidget.h"

#include <QGroupBox>
#include <QLayout>

PointEditWidget::PointEditWidget(Point* point, ActionHandler* actionHandler)
    : GroupBoxContainer(nullptr, "Point"), m_actionHandler(actionHandler), m_point(point) {
    auto* contentsLayout = m_groupBox->layout();

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(m_groupBox);

    auto* point1Widget = new XyWidget(m_point->point(), "pt");
    QObject::connect(point1Widget, &XyWidget::sendValues, this, &PointEditWidget::setPoint);

    contentsLayout->addWidget(point1Widget);

    auto* penWidget = new PenWidget(nullptr, m_point->index(), m_point->pen());
    QObject::connect(penWidget, &PenWidget::actionDone, m_actionHandler, &ActionHandler::doAction);
    contentsLayout->addWidget(penWidget);
}

void PointEditWidget::setPoint(QPointF newPoint) {
    m_point->setPoint(newPoint);
    m_actionHandler->draw();
}
