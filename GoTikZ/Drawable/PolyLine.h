//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POLYLINE_H
#define GOTIKZ_POLYLINE_H

#include "Drawable.h"

#include <QPointF>
#include <QVector>

class PolyLine_Stream;

class PolyLine : public Drawable
{
public:
    explicit PolyLine(const PolyLine_Stream& polyLineStream);

    void draw(QPainter* painter) override;

    std::pair<double, QPointF> snap(QPointF point) override;

private:
    QVector<QPointF> m_points;
};

#endif // GOTIKZ_POLYLINE_H
