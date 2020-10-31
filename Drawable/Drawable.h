//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include "Model/PrimitiveTypeEnum.h"

#include <QPen>

class QPainter;

namespace controller {
    class CoordinateConverter;
}

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

    void        setPen(const QPen& pen);
    void        setVisible(bool visible);
    bool        visible() const;
    size_t      index() const;
    const QPen& pen() const;

    virtual void                       draw(QPainter* painter, DRAW_FLAGS drawFlag,
                                            const controller::CoordinateConverter& coordinateConverter) const;
    virtual void                       translate(const QPointF& translation)        = 0;
    virtual void                       setPoint(size_t index, const QPointF& point) = 0;
    virtual double                     dist(const QPointF& point) const             = 0;
    virtual QPointF                    point(size_t index) const                    = 0;
    virtual std::pair<double, QPointF> snap(QPointF point)                          = 0;
    virtual PRIMITIVE_TYPE             type() const                                 = 0;

  protected:
    bool m_isVisible = true;
    QPen m_pen;

  private:
    size_t        m_index;
    static size_t s_maxIndex;
};

#endif // GOTIKZ_DRAWABLE_H
