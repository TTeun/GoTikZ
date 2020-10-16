//
// Created by pc on 15-10-20.
//

#include "Line_Stream.h"

#include "Line.h"

#include <QPainter>

void Line_Stream::stream(const QPointF& point) {
    m_point2     = point;
    m_shouldDraw = true;
}

void Line_Stream::draw(QPainter* painter) {
    Drawable::draw(painter);
    if (m_shouldDraw) {
        painter->drawLine(m_point1, m_point2);
    }
}

bool Line_Stream::addPoint(const QPointF& point, bool forceEnd) {
    m_point2 = point;
    return true;
}

Drawable* Line_Stream::drawable() {
    return new Line(*this);
}

std::pair<double, QPointF> Line_Stream::snap(QPointF point) {
    return {std::numeric_limits<double>::max(), point};
}
