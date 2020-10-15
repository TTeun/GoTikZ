//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_MATH_H
#define GOTIKZ_MATH_H

#include <QtCore/QPointF>

namespace Math {

double magnitude(const QPointF &point);

double distance(const QPointF &point1, const QPointF &point2);

} // namespace Math

#endif // GOTIKZ_MATH_H
