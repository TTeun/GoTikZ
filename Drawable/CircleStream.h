//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLESTREAM_H
#define GOTIKZ_CIRCLESTREAM_H

#include "StreamDrawable.h"

#include <QPointF>

namespace view {
    class Transform;
}

class CircleStream : public StreamDrawable {
  public:
    explicit CircleStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen), m_center(point) {
    }

    void                       stream(const QPointF& point) override;
    bool                       addPoint(const QPointF& point, bool forceEnd) override;
    Drawable*                  drawable() override;
    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                    const controller::CoordinateConverter& coordinateConverter) const override;
    std::pair<double, QPointF> snap(const QPointF& point) const override;
    double                     dist(const QPointF& point) const override;
    void                       translate(const QPointF& translation) override;
    PRIMITIVE_TYPE             type() const override;
    void                       setPoint(size_t index, const QPointF& point) override;
    QPointF                    point(size_t index) const override;

  private:
    friend class Circle;

    QPointF m_center;
    double  m_radius = 0.0;
};

#endif // GOTIKZ_CIRCLESTREAM_H
