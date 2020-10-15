//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLE_H
#define GOTIKZ_CIRCLE_H

#include "Drawable.h"

#include <QPointF>

class Circle_Stream;

class Circle : public Drawable {
public:
  explicit Circle(const Circle_Stream &circleStream);

  void draw(QPainter *painter) override;

  std::pair<double, QPointF> snap(QPointF point) override;

private:
  QPointF m_center;
  double m_radius;
};

#endif // GOTIKZ_CIRCLE_H
