//
// Created by pc on 15-10-20.
//

#include "Line.h"

#include "LineStream.h"

#include <Math/Math.h>
#include <QPainter>

Line::Line(const LineStream& lineStream)
    : Drawable(lineStream.m_pen), m_point1(lineStream.m_point1), m_point2(lineStream.m_point2) {
}

void Line::draw(QPainter* painter) {
    Drawable::draw(painter);
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
