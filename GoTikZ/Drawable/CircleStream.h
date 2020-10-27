//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLESTREAM_H
#define GOTIKZ_CIRCLESTREAM_H

#include "StreamDrawable.h"

#include <QPoint>

class CircleStream : public StreamDrawable {
  public:
    explicit CircleStream(const QPoint& point, const QPen& pen) : StreamDrawable(pen), m_center(point) {
    }

    void stream(const QPoint& point) override;

    bool addPoint(const QPoint& point, bool forceEnd) override;

    Drawable* drawable() override;

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPoint> snap(QPoint point) override;
    double                     dist(const QPoint& point) const override;

  private:
    friend class Circle;

    QPoint m_center;
    double  m_radius = 0.0;
};

#endif // GOTIKZ_CIRCLESTREAM_H
