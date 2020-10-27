//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include <QPen>

class QPainter;
class ActionHandler;
class GroupBoxContainer;

class Drawable {
  protected:
    explicit Drawable(QPen pen);

  public:
    enum class DRAW_FLAGS { NONE, SELECTED, HIGHLIGHTED };

    virtual void                       draw(QPainter* painter, DRAW_FLAGS drawFlag) const;
    virtual double                     dist(const QPoint& point) const = 0;
    virtual std::pair<double, QPoint> snap(QPoint point)              = 0;
    size_t                             index() const;
    virtual GroupBoxContainer*         toWidget(ActionHandler* actionHandler);
    void                               setPen(const QPen& pen);

    const QPen& pen() const;

  protected:
    QPen m_pen;

  private:
    size_t        m_index;
    static size_t s_maxIndex;
};

#endif // GOTIKZ_DRAWABLE_H
