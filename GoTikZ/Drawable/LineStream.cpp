//
// Created by pc on 15-10-20.
//

#include "LineStream.h"

#include "Line.h"

#include <Math/Math.h>
#include <QPainter>

void LineStream::stream(const QPointF& point) {
    m_point2     = point;
    m_shouldDraw = true;
}

void LineStream::draw(QPainter* painter, DRAW_FLAGS drawFlag) const {
    Drawable::draw(painter, drawFlag);
    if (m_shouldDraw) {
        painter->drawLine(m_point1, m_point2);
    }
}

bool LineStream::addPoint(const QPointF& point, bool forceEnd) {
    m_point2 = point;
    return true;
}

Drawable* LineStream::drawable() {
    return new Line(*this);
}

std::pair<double, QPointF> LineStream::snap(QPointF point) {
    return {std::numeric_limits<double>::max(), point};
}

double LineStream::dist(const QPointF& point) const {
    return std::min(Math::distance(point, m_point1), Math::distance(point, m_point2));
}
