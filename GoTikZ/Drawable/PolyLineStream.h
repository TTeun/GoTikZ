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
    PolyLineStream(const QPointF& point, const QPen& pen);

    void                       draw(QPainter* painter) const override;
    void                       stream(const QPointF& point) override;
    bool                       addPoint(const QPointF& point, bool forceEnd) override;
    Drawable*                  drawable() override;
    std::pair<double, QPointF> snap(QPointF point) override;

  private:
    std::vector<QPointF> m_points;
};

#endif // GOTIKZ_POLYLINESTREAM_H
