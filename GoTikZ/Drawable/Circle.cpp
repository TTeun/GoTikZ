//
// Created by pc on 15-10-20.
//

#include "Circle.h"

#include "Circle_Stream.h"

#include <Math/Math.h>
#include <QPainter>

Circle::Circle(const Circle_Stream &circleStream)
    : Drawable(circleStream.m_color), m_center(circleStream.m_center),
      m_radius(circleStream.m_radius) {}

void Circle::draw(QPainter *painter) {
  Drawable::draw(painter);
  painter->drawEllipse(m_center.x() - m_radius, m_center.y() - m_radius,
                       2 * m_radius, 2 * m_radius);
}

std::pair<double, QPointF> Circle::snap(QPointF point) {
  const auto difference = point - m_center;
  const auto closest =
      m_center + m_radius * difference / Math::magnitude(difference);

  return {Math::magnitude(point - closest), closest};
}
