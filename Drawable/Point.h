//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POINT_H
#define GOTIKZ_POINT_H

#include "Drawable.h"

#include <QPointF>

namespace View {
    class Transform;
}

namespace Controller {
    class ActionHandler;
}

class Point : public Drawable {
  public:
    Point(QPointF point, const QPen& pen) : Drawable(pen), m_point(point) {
    }

    void draw(QPainter* painter, DRAW_FLAGS drawFlag, const View::Transform& transform) const override;

    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;
    void                       setPoint(const QPointF& newPoint);
    QPointF                    point() const;
    QWidget*                   toWidget(Controller::ActionHandler* actionHandler) override;

    void translate(const QPointF& translation) override;

  private:
    QPointF m_point;
};

#endif // GOTIKZ_POINT_H
