//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLESTREAM_H
#define GOTIKZ_CIRCLESTREAM_H

#include "StreamDrawable.h"

#include <QPointF>

class CircleStream : public StreamDrawable {
  public:
    explicit CircleStream(const QPointF& point, const QPen& pen) : StreamDrawable(pen), m_center(point) {
    }

    void stream(const QPointF& point) override;

    bool addPoint(const QPointF& point, bool forceEnd) override;

    Drawable* drawable() override;

    void draw(QPainter* painter, DRAW_FLAGS drawFlag, const Transform& transform) const override;

    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;

    void translate(const QPointF translation) override {
        m_center += translation;
    }


  private:
    friend class Circle;

    QPointF m_center;
    double  m_radius = 0.0;
};

#endif // GOTIKZ_CIRCLESTREAM_H
