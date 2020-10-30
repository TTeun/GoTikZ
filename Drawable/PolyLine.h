//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POLYLINE_H
#define GOTIKZ_POLYLINE_H

#include "Drawable.h"

#include <QPointF>
#include <vector>

namespace view {
    class Transform;
}

class PolyLineStream;

class PolyLine : public Drawable {
  public:
    explicit PolyLine(const PolyLineStream& polyLineStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag, const view::Transform& transform) const override;
    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;
    void                       translate(const QPointF& translation) override;
    PRIMITIVE_TYPE             type() const override;
    size_t                     numberOfPoints() const;
    void                       setPoint(size_t index, const QPointF& point) override;
    QPointF                    point(size_t index) const override;

  private:
  public:
    const std::vector<QPointF>& points() const;
  private:
    std::vector<QPointF> m_points;
};

#endif // GOTIKZ_POLYLINE_H
