//
// Created by pc on 15-10-20.
//

#include "PolyLineStream.h"
#include"../States/Transform.h"

#include "PolyLine.h"
#include <QPainter>

#include "Math/Math.h"

PolyLineStream::PolyLineStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen) {
    m_points.push_back(point);
    m_points.push_back(point);
}

void PolyLineStream::draw(QPainter* painter, DRAW_FLAGS drawFlag, const Transform &transform) const {
    assert(m_points.size() > 1);
    Drawable::draw(painter, drawFlag, transform);
    for (size_t i = 1; i != m_points.size(); ++i) {
        painter->drawLine(transform.applyTransform(m_points[i - 1]), transform.applyTransform(m_points[i]));
    }
}

void PolyLineStream::stream(const QPointF& point) {
    m_points.back() = point;
}

bool PolyLineStream::addPoint(const QPointF& point, bool forceEnd) {
    m_points.back() = point;
    m_points.push_back(point);
    return forceEnd;
}

Drawable* PolyLineStream::drawable() {
    return new PolyLine(*this);
}

std::pair<double, QPointF> PolyLineStream::snap(QPointF point) {
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
    double result = std::numeric_limits<double>::max();
    for (const auto& el : m_points) {
        result = std::min(Math::distance(point, el), result);
    }
    return result;
}

void PolyLineStream::translate(const QPointF& translation) {
    for (auto& el : m_points){
        el += translation;
    }
}
