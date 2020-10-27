//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POLYLINESTREAM_H
#define GOTIKZ_POLYLINESTREAM_H

#include "StreamDrawable.h"

#include <vector>

class PolyLine;

class PolyLineStream : public StreamDrawable {
    friend class PolyLine;

  public:
    PolyLineStream(const QPoint& point, const QPen& pen);

    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;
    void                       stream(const QPoint& point) override;
    bool                       addPoint(const QPoint& point, bool forceEnd) override;
    Drawable*                  drawable() override;
    std::pair<double, QPoint> snap(QPoint point) override;
    double                     dist(const QPoint& point) const override;

  private:
    std::vector<QPoint> m_points;
};

#endif // GOTIKZ_POLYLINESTREAM_H
