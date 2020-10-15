//
// Created by pc on 15-10-20.
//

#include "PolyLine.h"

#include "PolyLine_Stream.h"

#include <Math/Math.h>
#include <QPainter>

PolyLine::PolyLine(const PolyLine_Stream &polyLineStream)
    : Drawable(polyLineStream.m_color), m_points(polyLineStream.m_points) {
  assert(m_points.size() > 2);
  m_points.resize(m_points.size() - 1ul);
}

void PolyLine::draw(QPainter *painter) {
  assert(m_points.size() > 1);
  Drawable::draw(painter);
  for (long i = 1; i != m_points.size(); ++i) {
    painter->drawLine(m_points[i - 1], m_points[i]);
  }
}

std::pair<double, QPointF> PolyLine::snap(QPointF point) {
  auto initial =
      std::pair<double, QPointF>(std::numeric_limits<double>::max(), point);
  for (auto &el : m_points) {
    if (Math::magnitude(point - el) < initial.first) {
      initial = {Math::magnitude(point - el), el};
    }
  }
  return initial;
}
