//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLE_H
#define GOTIKZ_CIRCLE_H

#include "Controller/Controller.h"
#include "Drawable.h"

#include <QPointF>

namespace view {
    class Transform;
}

class CircleStream;

class Circle : public Drawable {
  public:
    explicit Circle(const CircleStream& circleStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                    const controller::CoordinateConverter& coordinateConverter) const override;
    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;
    QPointF                    center() const;
    double                     radius() const;
    void                       setCenter(const QPointF& newCenter);
    void                       setRadius(double newRadius);
    void                       translate(const QPointF& translation) override;
    PRIMITIVE_TYPE             type() const override;
    void                       setPoint(size_t index, const QPointF& point) override;
    QPointF                    point(size_t index) const override;

  private:
    QPointF m_center;
    double  m_radius;
};

#endif // GOTIKZ_CIRCLE_H
