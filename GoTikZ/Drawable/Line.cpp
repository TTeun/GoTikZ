//
// Created by pc on 15-10-20.
//

#include "Line.h"

#include "LineStream.h"

#include <Math/Math.h>
#include <QPainter>
#include <Widgets/DrawableEditWidgets/LineEditWidget.h>

Line::Line(const LineStream& lineStream)
    : Drawable(lineStream.m_pen), m_point1(lineStream.m_point1), m_point2(lineStream.m_point2) {
}

void Line::draw(QPainter* painter, DRAW_FLAGS drawFlag) const {
    Drawable::draw(painter, drawFlag);
    painter->drawLine(m_point1, m_point2);
}
std::pair<double, QPointF> Line::snap(QPointF point) {
    const double d1 = Math::magnitude(point - m_point1);
    const double d2 = Math::magnitude(point - m_point2);
    if (d1 < d2) {
        return {d1, m_point1};
    } else {
        return {d2, m_point2};
    }
}

double Line::dist(const QPointF& point) const {
    return Math::pointToLineDistance({m_point1, m_point2}, point);
}

void Line::setPoint1(const QPointF& newPoint) {
    m_point1 = newPoint;
}

void Line::setPoint2(const QPointF& newPoint) {
    m_point2 = newPoint;
}

QPointF Line::point1() const {
    return m_point1;
}
QPointF Line::point2() const {
    return m_point2;
}
GroupBoxContainer* Line::toWidget(ActionHandler* actionHandler) {
    return new LineEditWidget(this, actionHandler);
}
