//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include <QPen>

class QPainter;

class Drawable
{
protected:
    explicit Drawable(QPen  pen);

public:
    virtual void draw(QPainter* painter);

    virtual std::pair<double, QPointF> snap(QPointF point) = 0;

protected:
    QPen m_pen;
};

#endif // GOTIKZ_DRAWABLE_H
