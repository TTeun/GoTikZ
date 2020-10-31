//
// Created by pc on 15-10-20.
//

#include "PolyLine.h"

#include "Controller/CoordinateConverter.h"
#include "Drawable/PolyLineStream.h"

#include <Math/Math.h>
#include <QPainter>

PolyLine::PolyLine(const PolyLineStream& polyLineStream)
    : Drawable(polyLineStream.m_pen), m_points(polyLineStream.m_points) {
    assert(m_points.size() > 2);
    m_points.resize(m_points.size() - 1ul);
}

void PolyLine::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                    const controller::CoordinateConverter& coordinateConverter) const {
    assert(m_isVisible);
    assert(m_points.size() > 1);
    Drawable::draw(painter, drawFlag, coordinateConverter);
    for (size_t i = 1; i != m_points.size(); ++i) {
        painter->drawLine(coordinateConverter.worldToScreen(m_points[i - 1]),
                          coordinateConverter.worldToScreen(m_points[i]));
    }
}

std::pair<double, QPointF> PolyLine::snap(QPointF point) {
    assert(m_isVisible);
    auto snapData = std::pair<double, QPointF>(std::numeric_limits<double>::max(), point);
    for (auto& el : m_points) {
        if (Math::magnitude(point - el) < snapData.first) {
            snapData = {Math::magnitude(point - el), el};
        }
    }
    return snapData;
}

double PolyLine::dist(const QPointF& point) const {
    assert(m_isVisible);
    double result = std::numeric_limits<double>::max();
    for (size_t i = 1; i != m_points.size(); ++i) {
        result = std::min(result, Math::pointToLineDistance({m_points[i - 1], m_points[i]}, point));
    }
    return result;
}

void PolyLine::translate(const QPointF& translation) {
    assert(m_isVisible);
    for (auto& el : m_points) {
        el += translation;
    }
}

PRIMITIVE_TYPE PolyLine::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::POLY_LINE;
}

size_t PolyLine::numberOfPoints() const {
    assert(m_isVisible);
    return m_points.size();
}

const std::vector<QPointF>& PolyLine::points() const {
    assert(m_isVisible);
    return m_points;
}

void PolyLine::setPoint(size_t index, const QPointF& point) {
    assert(m_isVisible);
    m_points[index] = point;
}

QPointF PolyLine::point(size_t index) const {
    assert(m_isVisible);
    return m_points[index];
}
