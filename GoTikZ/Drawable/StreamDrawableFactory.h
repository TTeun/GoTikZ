//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_STREAMDRAWABLEFACTORY_H
#define GOTIKZ_STREAMDRAWABLEFACTORY_H

#include "StreamDrawable.h"
#include <QtCore/QPointF>
#include <Widgets/drawwidget.h>

class StreamDrawableFactory {

public:
  static StreamDrawable *make(QPointF point, DrawWidget::DRAW_TYPE type,
                              QColor color);
};

#endif // GOTIKZ_STREAMDRAWABLEFACTORY_H
