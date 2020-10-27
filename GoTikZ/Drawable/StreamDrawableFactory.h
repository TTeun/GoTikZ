//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_STREAMDRAWABLEFACTORY_H
#define GOTIKZ_STREAMDRAWABLEFACTORY_H

#include "Model/MousePointerTypeEnum.h"

#include <QPen>

class QPoint;
class StreamDrawable;

class StreamDrawableFactory {
  public:
    static StreamDrawable* make(const QPoint& point, MOUSE_POINTER_TYPE type, const QPen& pen);
};

#endif // GOTIKZ_STREAMDRAWABLEFACTORY_H
