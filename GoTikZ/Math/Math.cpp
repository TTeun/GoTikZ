//
// Created by pc on 15-10-20.
//

#include "Math.h"

#include <QPoint>
#include <cmath>

namespace Math {
double magnitude(const QPoint& point) {
    const auto x = point.x();
    const auto y = point.y();
    return std::sqrt(x * x + y * y);
}

double distance(const QPoint& point1, const QPoint& point2) {
    return magnitude(point2 - point1);
}

} // namespace Math