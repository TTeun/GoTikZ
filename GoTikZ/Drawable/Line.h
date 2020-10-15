//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_H
#define GOTIKZ_LINE_H

#include "Drawable.h"
#include <QPointF>

class Line_Stream;

class Line : public Drawable {

public:
  explicit Line(const Line_Stream &lineStream);

  void draw(QPainter *painter) override;

  std::pair<double, QPointF> snap(QPointF point) override;

private:
  QPointF m_point1;
  QPointF m_point2;
};

#endif // GOTIKZ_LINE_H
