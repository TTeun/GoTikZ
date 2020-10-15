//
// Created by pc on 15-10-20.
//

#include "StreamDrawableFactory.h"
#include "Circle_Stream.h"
#include "Line_Stream.h"
#include "PolyLine_Stream.h"

StreamDrawable *StreamDrawableFactory::make(QPointF point,
                                            DrawWidget::DRAW_TYPE type,
                                            QColor color) {
  assert(type != DrawWidget::DRAW_TYPE::POINT);
  switch (type) {
  case DrawWidget::DRAW_TYPE::LINE:
    return new Line_Stream(point, color);
    break;
  case DrawWidget::DRAW_TYPE::CIRCLE:
    return new Circle_Stream(point, std::move(color));
    break;
  case DrawWidget::DRAW_TYPE::POLY_LINE:
    return new PolyLine_Stream(point, color);
    break;
  default:
    assert(false);
  }
}
