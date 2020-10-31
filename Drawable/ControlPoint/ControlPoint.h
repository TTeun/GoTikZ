//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_CONTROLPOINT_H
#define GOTIKZ_CONTROLPOINT_H

#include "Drawable/ControlPoint/PointInterface.h"
#include "Drawable/Point.h"

#include <QDebug>

class ControlPoint : public Point {

  public:
    ControlPoint(const QPointF& point, const QPen& pen, PointInterface pointSetFunctor);

    void      translate(const QPointF& translation) override;
    void      draw(QPainter* painter, DRAW_FLAGS drawFlag,
                   const controller::CoordinateConverter& coordinateConverter) const override;
    void      update();
    void      setHighlighted(bool highlighted);
    Drawable* drawable() const;


  private:
    bool                 m_isHighlighted = false;
    const PointInterface m_pointInterface;
};

#endif // GOTIKZ_CONTROLPOINT_H
