//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_H
#define GOTIKZ_LINE_H

#include "Drawable.h"

#include <QPoint>

class LineStream;

class Line : public Drawable {

  public:
    explicit Line(const LineStream& lineStream);

    void draw(QPainter* painter, DRAW_FLAGS drawFlag) const override;

    std::pair<double, QPoint> snap(QPoint point) override;

    double dist(const QPoint& point) const override;

    GroupBoxContainer* toWidget(ActionHandler* actionHandler) override;

    QPoint point1() const;

    QPoint point2() const;

    void setPoint1(const QPoint& newPoint);

    void setPoint2(const QPoint& newPoint);

  private:
    QPoint m_point1;
    QPoint m_point2;
};

#endif // GOTIKZ_LINE_H
