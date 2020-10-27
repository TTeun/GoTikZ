//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLE_H
#define GOTIKZ_CIRCLE_H

#include "Drawable.h"

#include <QPointF>

class CircleStream;

class Circle : public Drawable {
  public:
    explicit Circle(const CircleStream& circleStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPointF> snap(QPointF point) override;

    double dist(const QPointF& point) const override;

    GroupBoxContainer* toWidget(ActionHandler* actionHandler) override;

    QPointF center() const;

    void setCenter(const QPointF& newCenter);

  private:
    QPointF m_center;
    double  m_radius;
};

#endif // GOTIKZ_CIRCLE_H
