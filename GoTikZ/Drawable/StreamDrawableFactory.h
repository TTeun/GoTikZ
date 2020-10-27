//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_STREAMDRAWABLEFACTORY_H
#define GOTIKZ_STREAMDRAWABLEFACTORY_H

#include "Widgets/DrawWidget.h"

class QPointF;
class StreamDrawable;

class StreamDrawableFactory {
  public:
    static StreamDrawable* make(const QPointF& point, Drawable::PRIMITIVE_TYPE type, const QPen& pen);
};

#endif // GOTIKZ_STREAMDRAWABLEFACTORY_H
