//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINESTREAM_H
#define GOTIKZ_LINESTREAM_H

#include "StreamDrawable.h"

#include <QPoint>

class Line;

class LineStream : public StreamDrawable {
  public:
    LineStream(const QPoint& point, const QPen& pen) : StreamDrawable(pen), m_point1(point) {
    }

    void                       stream(const QPoint& point) override;
    bool                       addPoint(const QPoint& point, bool forceEnd) override;
    Drawable*                  drawable() override;
    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;
    std::pair<double, QPoint> snap(QPoint point) override;

    double dist(const QPoint& point) const override;

  private:
    friend class Line;

    QPoint m_point1;
    QPoint m_point2;
};

#endif // GOTIKZ_LINESTREAM_H
