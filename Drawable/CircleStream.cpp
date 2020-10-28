//
// Created by pc on 15-10-20.
//

#include "CircleStream.h"

#include "Circle.h"
#include "../States/Transform.h"

#include <Math/Math.h>
#include <QPainter>

void CircleStream::stream(const QPointF& point) {
    m_radius     = Math::distance(m_center, point);
    m_shouldDraw = true;
}

void CircleStream::draw(QPainter* painter, DRAW_FLAGS drawFlag, const Transform& transform) const {
    Drawable::draw(painter, drawFlag, transform);
    if (m_shouldDraw) {
        painter->drawEllipse(transform.applyTransform(m_center),  m_radius * transform.scale(),  m_radius * transform.scale());
    }
}

bool CircleStream::addPoint(const QPointF& point, bool forceEnd) {
    m_radius = Math::distance(m_center, point);
    return true;
}

Drawable* CircleStream::drawable() {
    return new Circle(*this);
}

std::pair<double, QPointF> CircleStream::snap(QPointF point) {
    return {std::numeric_limits<double>::max(), QPointF()};
}

double CircleStream::dist(const QPointF& point) const {
    const double distToCenter = Math::distance(point, m_center);
    return std::abs(distToCenter - m_radius);
}
