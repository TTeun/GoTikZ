//
// Created by pc on 27-10-20.
//

#include "LineEditWidget.h"

#include "../../Actions/ActionHandler.h"
#include "../../Drawable/Line.h"
#include "Widgets/AuxWidgets/XyWidget.h"
#include "Widgets/PenWidget.h"

#include <QGroupBox>
#include <QLayout>

LineEditWidget::LineEditWidget(Line* line, ActionHandler* actionHandler)
    : GroupBoxContainer(nullptr, "Line"), m_line(line), m_actionHandler(actionHandler) {
    auto* contentsLayout = layout();

    auto* point1Widget = new XyWidget(m_line->point1(), "p1");
    QObject::connect(point1Widget, &XyWidget::sendValues, this, &LineEditWidget::setPoint1);

    auto* point2Widget = new XyWidget(m_line->point2(), "p2");
    QObject::connect(point2Widget, &XyWidget::sendValues, this, &LineEditWidget::setPoint2);

    contentsLayout->addWidget(point1Widget);
    contentsLayout->addWidget(point2Widget);

    auto* penWidget = new PenWidget(nullptr, line->index(), m_line->pen());
    QObject::connect(penWidget, &PenWidget::actionDone, m_actionHandler, &ActionHandler::doAction);
    contentsLayout->addWidget(penWidget->groupBox());
}

void LineEditWidget::setPoint1(QPointF newPoint) {
    m_line->setPoint1(newPoint);
    m_actionHandler->draw();
}

void LineEditWidget::setPoint2(QPointF newPoint) {
    m_line->setPoint2(newPoint);
    m_actionHandler->draw();
}
