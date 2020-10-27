//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_H
#define GOTIKZ_LINE_H

#include "Drawable.h"

#include <QPointF>

class LineStream;

class Line : public Drawable {

  public:
    explicit Line(const LineStream& lineStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPointF> snap(QPointF point) override;

    double dist(const QPointF& point) const override;

  private:
    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINE_H
