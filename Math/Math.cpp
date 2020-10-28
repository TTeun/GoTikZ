//
// Created by pc on 15-10-20.
//

#include "Math.h"

#include <QPointF>
#include <cmath>

namespace Math {
double magnitudeSquared(const QPointF& point) {
    const auto x = point.x();
    const auto y = point.y();
    return x * x + y * y;
}

double distanceSquared(const QPointF& point1, const QPointF& point2) {
    return magnitudeSquared(point2 - point1);
}

double magnitude(const QPointF& point) {
    return std::sqrt(magnitudeSquared(point));
}

double distance(const QPointF& point1, const QPointF& point2) {
    return magnitude(point2 - point1);
}

double dot(const QPointF& point1, const QPointF& point2) {
    return point1.x() * point2.x() + point1.y() * point2.y();
}

double pointToLineDistance(std::pair<const QPointF&, const QPointF&> line, const QPointF& point) {
    const double lineLength = Math::distanceSquared(line.first, line.second);
    if (lineLength == 0.0) {
        return distance(line.first, point);
    }
    const float t = std::max(0.0, std::min(1.0, Math::dot(point - line.first, line.second - line.first) / lineLength));
    const QPointF projection = line.first + t * (line.second - line.first);
    return distance(point, projection);
}

} // namespace Math