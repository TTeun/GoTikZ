//
// Created by pc on 15-10-20.
//

#include "Math.h"

#include <QPoint>
#include <cmath>

namespace Math {
double magnitude(const QPointF &point) {
  const auto x = point.x();
  const auto y = point.y();
  return std::sqrt(x * x + y * y);
}

double distance(const QPointF &point1, const QPointF &point2) {
  return magnitude(point2 - point1);
}

} // namespace Math