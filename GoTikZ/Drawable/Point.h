//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POINT_H
#define GOTIKZ_POINT_H

#include "Drawable.h"

#include <QPointF>

class Point : public Drawable {
  public:
    Point(QPointF point, const QPen& pen) : Drawable(pen), m_point(point) {
    }

    void draw(QPainter* painter) const override;

    std::pair<double, QPointF> snap(QPointF point) override;

  private:
    QPointF m_point;
};

#endif // GOTIKZ_POINT_H
