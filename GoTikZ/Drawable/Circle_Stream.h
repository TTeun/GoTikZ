//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_CIRCLE_STREAM_H
#define GOTIKZ_CIRCLE_STREAM_H

#include "StreamDrawable.h"

#include <QtCore/QPointF>

class Circle_Stream : public StreamDrawable {
public:
  explicit Circle_Stream(const QPointF &point, QColor color)
      : StreamDrawable(std::move(color)), m_center(point) {}

  void stream(const QPointF &point) override;

  bool addPoint(const QPointF &point, bool forceEnd) override;

  Drawable *drawable() override;

  void draw(QPainter *painter) override;

  std::pair<double, QPointF> snap(QPointF point) override;

private:
  friend class Circle;

  QPointF m_center;
  double m_radius = 0.0;
};

#endif // GOTIKZ_CIRCLE_STREAM_H
