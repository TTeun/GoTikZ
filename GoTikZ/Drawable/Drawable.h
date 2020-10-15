//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_DRAWABLE_H
#define GOTIKZ_DRAWABLE_H

#include <QColor>
#include <QPainter>
#include <QPointF>
#include <tuple>

class QPainter;

class Drawable {
public:
  explicit Drawable(const QColor &color) : m_color(color) {}

  virtual void draw(QPainter *painter) { painter->setPen(QPen{m_color, 2}); };

  virtual std::pair<double, QPointF> snap(QPointF point) = 0;

  QColor m_color;
};

#endif // GOTIKZ_DRAWABLE_H
