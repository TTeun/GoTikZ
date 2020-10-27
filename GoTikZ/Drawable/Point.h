//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POINT_H
#define GOTIKZ_POINT_H

#include "Drawable.h"

#include <QPoint>

class Point : public Drawable {
  public:
    Point(QPoint point, const QPen& pen) : Drawable(pen), m_point(point) {
    }

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPoint> snap(QPoint point) override;
    double                     dist(const QPoint& point) const override;

  private:
    QPoint m_point;
};

#endif // GOTIKZ_POINT_H
