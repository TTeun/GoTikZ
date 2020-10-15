//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LINE_STREAM_H
#define GOTIKZ_LINE_STREAM_H

#include "StreamDrawable.h"

#include <QtCore/QPointF>

class Line;

class Line_Stream : public StreamDrawable {
public:
  Line_Stream(const QPointF &point, const QColor &color)
      : StreamDrawable(color), m_point1(point) {}

  void stream(const QPointF &point) override;
  bool addPoint(const QPointF &point, bool forceEnd = false) override;
  Drawable *drawable() override;
  void draw(QPainter *painter) override;
  std::pair<double, QPointF> snap(QPointF point) override;

private:
  friend class Line;

  QPointF m_point1;
  QPointF m_point2;
};

#endif // GOTIKZ_LINE_STREAM_H
