//
// Created by pc on 15-10-20.
//

#include "StreamDrawableFactory.h"

#include "CircleStream.h"
#include "LineStream.h"
#include "PolyLineStream.h"

StreamDrawable* StreamDrawableFactory::make(const QPointF& point, DrawWidget::PRIMITIVE_TYPE type, const QPen& pen) {
    assert(type != DrawWidget::PRIMITIVE_TYPE::POINT);
    switch (type) {
        case DrawWidget::PRIMITIVE_TYPE::LINE:
            return new LineStream(point, pen);
            break;
        case DrawWidget::PRIMITIVE_TYPE::CIRCLE:
            return new CircleStream(point, pen);
            break;
        case DrawWidget::PRIMITIVE_TYPE::POLY_LINE:
            return new PolyLineStream(point, pen);
            break;
        default:
            assert(false);
    }
    return nullptr;
}
