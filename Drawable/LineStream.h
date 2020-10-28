//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINESTREAM_H
#define GOTIKZ_LINESTREAM_H

#include "StreamDrawable.h"

#include <QPointF>

namespace View {
    class Transform;
}

class Line;

class LineStream : public StreamDrawable {
  public:
    LineStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen), m_point1(point) {
    }

    void                       stream(const QPointF& point) override;
    bool                       addPoint(const QPointF& point, bool forceEnd) override;
    Drawable*                  drawable() override;
    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag, const View::Transform& transform) const override;
    std::pair<double, QPointF> snap(QPointF point) override;

    double dist(const QPointF& point) const override;
    void   translate(const QPointF& translation) override;

  private:
    friend class Line;

    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINESTREAM_H
