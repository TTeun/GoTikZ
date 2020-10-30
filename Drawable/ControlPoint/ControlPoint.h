//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_CONTROLPOINT_H
#define GOTIKZ_CONTROLPOINT_H

#include "Drawable/ControlPoint/PointSetFunctor.h"
#include "Drawable/Point.h"

#include <QDebug>

class ControlPoint : public Point {

  public:
    ControlPoint(const QPointF& point, const QPen& pen, PointSetFunctor pointSetFunctor);

    void translate(const QPointF& translation) override;
    void draw(QPainter* painter, DRAW_FLAGS drawFlag, const view::Transform& transform) const override;
    void update();

    Drawable* drawable() const;

  private:
    const PointSetFunctor m_pointSetFunctor;
};

#endif // GOTIKZ_CONTROLPOINT_H
