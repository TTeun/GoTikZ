//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLE_H
#define GOTIKZ_CIRCLE_H

#include "Drawable.h"

#include <QPoint>

class CircleStream;

class Circle : public Drawable {
  public:
    explicit Circle(const CircleStream& circleStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPoint> snap(QPoint point) override;

    double dist(const QPoint& point) const override;

    GroupBoxContainer* toWidget(ActionHandler* actionHandler) override;

    QPoint center() const;

    double radius() const {
        return m_radius;
    }

    void setCenter(const QPoint& newCenter);

    void setRadius(double newRadius);

  private:
    QPoint m_center;
    double  m_radius;
};

#endif // GOTIKZ_CIRCLE_H
