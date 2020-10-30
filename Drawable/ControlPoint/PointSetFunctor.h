//
// Created by pc on 30-10-20.
//

#ifndef GOTIKZ_POINTSETFUNCTOR_H
#define GOTIKZ_POINTSETFUNCTOR_H

#include <cstddef>

class Drawable;
class QPointF;

class PointSetFunctor {

  public:
    PointSetFunctor(size_t index, Drawable* drawable);

    void      setPoint(const QPointF& newPoint) const;
    QPointF   point() const;
    Drawable* drawable() const;

  private:
    const size_t    m_index;
    Drawable* const m_drawable;
};

#endif // GOTIKZ_POINTSETFUNCTOR_H
