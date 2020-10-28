//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_H
#define GOTIKZ_LINE_H

#include "Drawable.h"

#include <QPointF>

class LineStream;

class Line : public Drawable {

  public:
    explicit Line(const LineStream& lineStream);
    Line(const QPointF& point1, const QPointF& point2);

    void                       draw(QPainter* painter, DRAW_FLAGS drawFlag, const Transform& transform) const override;
    std::pair<double, QPointF> snap(QPointF point) override;
    double                     dist(const QPointF& point) const override;
    GroupBoxContainer*         toWidget(ActionHandler* actionHandler) override;
    QPointF                    point1() const;
    QPointF                    point2() const;
    void                       setPoint1(const QPointF& newPoint);
    void                       setPoint2(const QPointF& newPoint);
    void translate(const QPointF translation) override {
        m_point1 += translation;
        m_point2 += translation;
    }


  private:
    QPointF m_point1;
    QPointF m_point2;
};

#endif // GOTIKZ_LINE_H
