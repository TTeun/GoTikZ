//
// Created by pc on 15-10-20.
//

#include "CircleStream.h"

#include "Circle.h"
#include "View/Transform.h"

#include <Math/Math.h>
#include <QPainter>

void CircleStream::stream(const QPointF& point) {
    m_radius     = math::distance(m_center, point);
    m_shouldDraw = true;
}

void CircleStream::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                        const controller::CoordinateConverter& coordinateConverter) const {
    assert(m_isVisible);
    Drawable::draw(painter, drawFlag, coordinateConverter);
    if (m_shouldDraw) {
        painter->drawEllipse(coordinateConverter.worldToScreen(m_center),
                             coordinateConverter.worldToScreenDistance(m_radius),
                             coordinateConverter.worldToScreenDistance(m_radius));
    }
}

bool CircleStream::addPoint(const QPointF& point, bool forceEnd) {
    assert(m_isVisible);
    m_radius = math::distance(m_center, point);
    return true;
}

Drawable* CircleStream::drawable() {
    assert(m_isVisible);
    return new Circle(*this);
}

std::pair<double, QPointF> CircleStream::snap(const QPointF& point) const {
    assert(m_isVisible);
    return {std::numeric_limits<double>::max(), QPointF()};
}

double CircleStream::dist(const QPointF& point) const {
    assert(m_isVisible);
    const double distToCenter = math::distance(point, m_center);
    return std::abs(distToCenter - m_radius);
}

void CircleStream::translate(const QPointF& translation) {
    assert(m_isVisible);
    m_center += translation;
}

PRIMITIVE_TYPE CircleStream::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::STREAM;
}

void CircleStream::setPoint(size_t index, const QPointF& point) {
    assert(m_isVisible);
    assert(false);
}

QPointF CircleStream::point(size_t index) const {
    assert(false);
    return QPointF{};
}
