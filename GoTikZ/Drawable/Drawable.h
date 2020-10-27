//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include <QPen>

class QPainter;

class Drawable {
  protected:
    explicit Drawable(QPen pen);

  public:
    enum class PRIMITIVE_TYPE { LINE, POINT, CIRCLE, POLY_LINE };

    virtual void draw(QPainter* painter) const;

    virtual std::pair<double, QPointF> snap(QPointF point) = 0;

    size_t index() const;

  protected:
    QPen m_pen;

  private:
    size_t        m_index;
    static size_t s_maxIndex;
};

#endif // GOTIKZ_DRAWABLE_H
