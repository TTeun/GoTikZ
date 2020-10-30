//
// Created by pc on 15-10-20.
//

#include "Line.h"

#include "Drawable/ControlPoint/ControlPoint.h"
#include "Drawable/LineStream.h"
#include "Math/Math.h"
#include "View/Transform.h"
#include "View/Widgets/DrawableEditWidgets/LineEditWidget.h"

#include <QPainter>

Line::Line(const LineStream& lineStream)
    : Drawable(lineStream.m_pen), m_point1(lineStream.m_point1), m_point2(lineStream.m_point2) {
}

void Line::draw(QPainter* painter, DRAW_FLAGS drawFlag, const view::Transform& transform) const {
    Drawable::draw(painter, drawFlag, transform);
    painter->drawLine(transform.applyTransform(m_point1), transform.applyTransform(m_point2));
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

void Line::translate(const QPointF& translation) {
    m_point1 += translation;
    m_point2 += translation;
}

PRIMITIVE_TYPE Line::type() const {
    return PRIMITIVE_TYPE::LINE;
}
void Line::setPoint(size_t index, const QPointF& point) {
    if (index == 0) {
        setPoint1(point);
    } else {
        setPoint2(point);
    }
}
QPointF Line::point(size_t index) const {
    if (index == 0) {
        return m_point1;
    } else {
        return m_point2;
    }
}
