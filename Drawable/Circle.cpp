//
// Created by pc on 15-10-20.
//

#include "Circle.h"

#include "CircleStream.h"
#include "Math/Math.h"
#include "View/Transform.h"
#include "View/Widgets/DrawableEditWidgets/CircleEditWidget.h"

#include <QPainter>

Circle::Circle(const CircleStream& circleStream)
    : Drawable(circleStream.m_pen), m_center(circleStream.m_center), m_radius(circleStream.m_radius) {
}

void Circle::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                  const controller::CoordinateConverter& coordinateConverter) const {
    Drawable::draw(painter, drawFlag, coordinateConverter);
    painter->drawEllipse(coordinateConverter.worldToScreen(m_center),
                         coordinateConverter.worldToScreenDistance(m_radius),
                         coordinateConverter.worldToScreenDistance(m_radius));
}

std::pair<double, QPointF> Circle::snap(const QPointF& point) const {
    assert(m_isVisible);
    const auto difference = point - m_center;
    const auto closest    = m_center + m_radius * difference / math::magnitude(difference);

    return {math::magnitude(point - closest), closest};
}

double Circle::dist(const QPointF& point) const {
    assert(m_isVisible);
    const double distToCenter = math::distance(point, m_center);
    return std::abs(distToCenter - m_radius);
}

QPointF Circle::center() const {
    assert(m_isVisible);
    return m_center;
}

double Circle::radius() const {
    assert(m_isVisible);
    return m_radius;
}

void Circle::setCenter(const QPointF& newCenter) {
    assert(m_isVisible);
    m_center = newCenter;
}

void Circle::setRadius(double newRadius) {
    assert(m_isVisible);
    m_radius = newRadius;
}

void Circle::translate(const QPointF& translation) {
    assert(m_isVisible);
    m_center += translation;
}

PRIMITIVE_TYPE Circle::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::CIRCLE;
}

void Circle::setPoint(size_t index, const QPointF& point) {
    assert(m_isVisible);
    if (index == 0) {
        setCenter(point);
    } else {

        setRadius(point.x() - m_center.x());
    }
}

QPointF Circle::point(size_t index) const {
    assert(m_isVisible);
    if (index == 0) {
        return m_center;
    } else {
        return m_center + QPointF(m_radius, 0);
    }
}
