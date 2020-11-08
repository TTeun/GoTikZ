//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_H
#define GOTIKZ_LINE_H

#include "Controller/Controller.h"
#include "Drawable.h"

#include <QPointF>

namespace view {
    class Transform;
}

class LineStream;

class Line : public Drawable {

  public:
    explicit Line(const LineStream& lineStream);
    Line(const QPointF& point1, const QPointF& point2);

    void           draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                    const controller::CoordinateConverter& coordinateConverter) const override;
    void           setPoint1(const QPointF& newPoint);
    void           setPoint2(const QPointF& newPoint);
    void           translate(const QPointF& translation) override;
    void           setPoint(size_t index, const QPointF& point) override;
    double         dist(const QPointF& point) const override;
    QPointF                    point(size_t index) const override;
    QPointF        point1() const;
    QPointF        point2() const;
    PRIMITIVE_TYPE type() const override;
    std::pair<double, QPointF> snap(const QPointF& point) const override;

  private:
    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINE_H
