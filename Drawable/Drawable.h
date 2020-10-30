//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include "Model/PrimitiveTypeEnum.h"

#include <QPen>

class QPainter;

namespace view {
    class Transform;
}

class GroupBoxContainer;
class ControlPoint;

class Drawable {
  protected:
    explicit Drawable(QPen pen);

  public:
    enum class DRAW_FLAGS { NONE, SELECTED, HIGHLIGHTED };

    size_t      index() const;
    void        setPen(const QPen& pen);
    const QPen& pen() const;

    virtual void    draw(QPainter* painter, DRAW_FLAGS drawFlag, const view::Transform& transform) const;
    virtual void    translate(const QPointF& translation)        = 0;
    virtual void    setPoint(size_t index, const QPointF& point) = 0;
    virtual double  dist(const QPointF& point) const             = 0;
    virtual QPointF point(size_t index) const                    = 0;
    virtual std::pair<double, QPointF> snap(QPointF point)       = 0;
    virtual PRIMITIVE_TYPE             type() const              = 0;

  protected:
    QPen m_pen;

  private:
    size_t        m_index;
    static size_t s_maxIndex;
};

#endif // GOTIKZ_DRAWABLE_H
