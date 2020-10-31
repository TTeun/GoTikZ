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

    void      stream(const QPointF& point) override;
    bool      addPoint(const QPointF& point, bool forceEnd) override;
    Drawable* drawable() override;
    void      draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                    const controller::CoordinateConverter& coordinateConverter) const override;
    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;
    void                       translate(const QPointF& translation) override;
    PRIMITIVE_TYPE             type() const override;
    void                       setPoint(size_t index, const QPointF& point) override;
    QPointF                    point(size_t index) const override;

  private:
    friend class Line;

    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINESTREAM_H
