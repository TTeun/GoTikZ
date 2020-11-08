//
// Created by pc on 15-10-20.
//

#include "LineStream.h"

#include "Controller/CoordinateConverter.h"
#include "Drawable/Line.h"

#include <Math/Math.h>
#include <QPainter>

LineStream::LineStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen), m_point1(point) {
}

void LineStream::stream(const QPointF& point) {
    assert(m_isVisible);
    m_point2     = point;
    m_shouldDraw = true;
}

void LineStream::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                      const controller::CoordinateConverter& coordinateConverter) const {
    assert(m_isVisible);
    Drawable::draw(painter, drawFlag, coordinateConverter);
    if (m_shouldDraw) {
        painter->drawLine(coordinateConverter.worldToScreen(m_point1), coordinateConverter.worldToScreen(m_point2));
    }
}

bool LineStream::addPoint(const QPointF& point, [[maybe_unused]] bool forceEnd) {
    assert(m_isVisible);
    m_point2 = point;
    return true;
}

Drawable* LineStream::drawable() {
    assert(m_isVisible);
    return new Line(*this);
}

std::pair<double, QPointF> LineStream::snap(const QPointF& point) const {
    assert(m_isVisible);
    return {std::numeric_limits<double>::max(), point};
}

double LineStream::dist(const QPointF& point) const {
    assert(m_isVisible);
    return std::min(math::distance(point, m_point1), math::distance(point, m_point2));
}

void LineStream::translate(const QPointF& translation) {
    assert(m_isVisible);
    m_point1 += translation;
    m_point2 += translation;
}

PRIMITIVE_TYPE LineStream::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::STREAM;
}

void LineStream::setPoint(size_t index, const QPointF& point) {
    assert(false);
}

QPointF LineStream::point(size_t index) const {
    assert(false);
    return QPointF{};
}
