//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_MATH_H
#define GOTIKZ_MATH_H

#include <tuple>

class QPointF;

namespace Math {

double magnitudeSquared(const QPointF& point);

double distanceSquared(const QPointF& point1, const QPointF& point2);

double magnitude(const QPointF& point);

double distance(const QPointF& point1, const QPointF& point2);

double dot(const QPointF& point1, const QPointF& point2);

double pointToLineDistance(std::pair<const QPointF&, const QPointF&> line, const QPointF& point);

} // namespace Math

#endif // GOTIKZ_MATH_H
