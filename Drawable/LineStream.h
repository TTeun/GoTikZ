//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINESTREAM_H
#define GOTIKZ_LINESTREAM_H

#include "StreamDrawable.h"

#include <QPointF>

namespace view {
    class Transform;
}

class Line;

class LineStream : public StreamDrawable {
  public:
    LineStream(const QPointF& point, const QPen& pen);

    void                       stream(const QPointF& point) override;
    void                       translate(const QPointF& translation) override;
    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                    const controller::CoordinateConverter& coordinateConverter) const override;
    void                       setPoint(size_t index, const QPointF& point) override;
    bool                       addPoint(const QPointF& point, bool forceEnd) override;
    double                     dist(const QPointF& point) const override;
    QPointF                    point(size_t index) const override;
    PRIMITIVE_TYPE             type() const override;
    Drawable*                  drawable() override;
    std::pair<double, QPointF> snap(const QPointF& point) const override;

  private:
    friend class Line;

    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINESTREAM_H
