//
// Created by pc on 15-10-20.
//

#include "Point.h"

#include <Math/Math.h>
#include <QPainter>

void Point::draw(QPainter* painter) const {
    Drawable::draw(painter);
    painter->drawPoint(m_point);
}

std::pair<double, QPointF> Point::snap(QPointF point) {
    return {Math::magnitude(point - m_point), m_point};
}
