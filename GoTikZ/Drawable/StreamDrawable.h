//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_STREAMDRAWABLE_H
#define GOTIKZ_STREAMDRAWABLE_H

#include "Drawable.h"

class QPoint;

class StreamDrawable : public Drawable {
  protected:
    explicit StreamDrawable(const QPen& pen) : Drawable(pen) {
    }

  public:
    virtual void      stream(const QPoint& point)                  = 0;
    virtual bool      addPoint(const QPoint& point, bool forceEnd) = 0;
    virtual Drawable* drawable()                                    = 0;

  protected:
    bool m_shouldDraw = false;
};

#endif // GOTIKZ_STREAMDRAWABLE_H
