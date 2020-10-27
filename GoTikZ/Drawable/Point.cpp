//
// Created by pc on 15-10-20.
//

#include "Point.h"

#include <Math/Math.h>
#include <QPainter>

void Point::draw(QPainter* painter, DRAW_FLAGS drawFlag) const {
    Drawable::draw(painter, drawFlag);
    painter->drawPoint(m_point);
}

std::pair<double, QPoint> Point::snap(QPoint point) {
    return {Math::magnitude(point - m_point), m_point};
}

double Point::dist(const QPoint& point) const {
    return Math::distance(point, m_point);
}
