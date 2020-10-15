//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_STREAMDRAWABLE_H
#define GOTIKZ_STREAMDRAWABLE_H

#include "Drawable.h"

class QPointF;

class StreamDrawable : public Drawable {
public:
  StreamDrawable(const QPen &pen) : Drawable(pen) {}

  virtual void stream(const QPointF &point) = 0;

  virtual bool addPoint(const QPointF &point, bool forceEnd = false) = 0;

  virtual Drawable *drawable() = 0;

protected:
  bool m_shouldDraw = false;
};

#endif // GOTIKZ_STREAMDRAWABLE_H
