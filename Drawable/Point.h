//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POINT_H
#define GOTIKZ_POINT_H

#include "Drawable.h"

#include <QPointF>

namespace view {
    class Transform;
}

namespace controller {
    class Controller;
}

class Point : public Drawable {
  public:
    Point(QPointF point, const QPen& pen) : Drawable(pen), m_point(point) {
    }

    void           draw(QPainter* painter, DRAW_FLAGS drawFlag, const view::Transform& transform) const override;
    void           setPoint(const QPointF& newPoint);
    void           translate(const QPointF& translation) override;
    double         dist(const QPointF& point) const override;
    QPointF        point() const;
    QPointF                    point(size_t index) const override;
    PRIMITIVE_TYPE type() const override;
    std::pair<double, QPointF> snap(QPointF point) override;

    void setPoint(size_t index, const QPointF& point) override;

  protected:
    QPointF m_point;
};

#endif // GOTIKZ_POINT_H
