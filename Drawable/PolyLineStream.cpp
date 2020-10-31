//
// Created by pc on 15-10-20.
//

#include "PolyLineStream.h"

#include "Controller/CoordinateConverter.h"
#include "Drawable/PolyLine.h"
#include "Math/Math.h"

#include <QPainter>

PolyLineStream::PolyLineStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen) {
    m_points.push_back(point);
    m_points.push_back(point);
}

void PolyLineStream::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                          const controller::CoordinateConverter& coordinateConverter) const {
    assert(m_isVisible);
    assert(m_points.size() > 1);
    Drawable::draw(painter, drawFlag, coordinateConverter);
    for (size_t i = 1; i != m_points.size(); ++i) {
        painter->drawLine(coordinateConverter.worldToScreen(m_points[i - 1]),
                          coordinateConverter.worldToScreen(m_points[i]));
    }
}

void PolyLineStream::stream(const QPointF& point) {
    assert(m_isVisible);
    m_points.back() = point;
}

bool PolyLineStream::addPoint(const QPointF& point, bool forceEnd) {
    assert(m_isVisible);
    m_points.back() = point;
    m_points.push_back(point);
    return forceEnd;
}

Drawable* PolyLineStream::drawable() {
    assert(m_isVisible);
    return new PolyLine(*this);
}

std::pair<double, QPointF> PolyLineStream::snap(QPointF point) {
    assert(m_isVisible);
    auto snapData = std::pair<double, QPointF>(std::numeric_limits<double>::max(), point);
    for (size_t i = 0; i != m_points.size() - 2; ++i) {
        const auto& el = m_points[i];
        if (Math::magnitude(point - el) < snapData.first) {
            snapData = {Math::magnitude(point - el), el};
        }
    }
    return snapData;
}

double PolyLineStream::dist(const QPointF& point) const {
    assert(m_isVisible);
    double result = std::numeric_limits<double>::max();
    for (const auto& el : m_points) {
        result = std::min(Math::distance(point, el), result);
    }
    return result;
}

void PolyLineStream::translate(const QPointF& translation) {
    assert(m_isVisible);
    for (auto& el : m_points) {
        el += translation;
    }
}

PRIMITIVE_TYPE PolyLineStream::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::STREAM;
}

void PolyLineStream::setPoint(size_t index, const QPointF& point) {
    assert(false);
}

QPointF PolyLineStream::point(size_t index) const {
    assert(false);
}
