//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POLYLINE_H
#define GOTIKZ_POLYLINE_H

#include "Drawable.h"

#include <QPointF>
#include <vector>

class PolyLineStream;

class PolyLine : public Drawable {
  public:
    explicit PolyLine(const PolyLineStream& polyLineStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPointF> snap(QPointF point) override;

    double dist(const QPointF& point) const override;

  private:
    std::vector<QPointF> m_points;
};

#endif // GOTIKZ_POLYLINE_H
