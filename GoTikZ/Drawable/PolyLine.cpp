//
// Created by pc on 15-10-20.
//

#include "PolyLine.h"

#include "PolyLineStream.h"

#include <Math/Math.h>
#include <QPainter>

PolyLine::PolyLine(const PolyLineStream& polyLineStream)
    : Drawable(polyLineStream.m_pen), m_points(polyLineStream.m_points) {
    assert(m_points.size() > 2);
    m_points.resize(m_points.size() - 1ul);
}

void PolyLine::draw(QPainter* painter, DRAW_FLAGS drawFlag) const {
    assert(m_points.size() > 1);
    Drawable::draw(painter, drawFlag);
    for (size_t i = 1; i != m_points.size(); ++i) {
        painter->drawLine(m_points[i - 1], m_points[i]);
    }
}

std::pair<double, QPointF> PolyLine::snap(QPointF point) {
    auto initial = std::pair<double, QPointF>(std::numeric_limits<double>::max(), point);
    for (auto& el : m_points) {
        if (Math::magnitude(point - el) < initial.first) {
            initial = {Math::magnitude(point - el), el};
        }
    }
    return initial;
}

double PolyLine::dist(const QPointF& point) const {
    double result = std::numeric_limits<double>::max();
    for (const auto& el : m_points) {
        result = std::min(Math::distance(point, el.toPoint()), result);
    }
    return result;
}
