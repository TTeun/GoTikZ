//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_POLYLINE_STREAM_H
#define GOTIKZ_POLYLINE_STREAM_H

#include "StreamDrawable.h"

#include <QVector>

class PolyLine;

class PolyLine_Stream : public StreamDrawable {
  friend class PolyLine;

public:
  PolyLine_Stream(QPointF point, const QPen &pen);

  void draw(QPainter *painter) override;
  void stream(const QPointF &point) override;
  bool addPoint(const QPointF &point, bool forceEnd = false) override;
  Drawable *drawable() override;
  std::pair<double, QPointF> snap(QPointF point) override;

private:
  QVector<QPointF> m_points;
};

#endif // GOTIKZ_POLYLINE_STREAM_H
