//
// Created by pc on 15-10-20.
//

#include "StreamDrawableFactory.h"

#include "CircleStream.h"
#include "LineStream.h"
#include "Model/MousePointerTypeEnum.h"
#include "PolyLineStream.h"

StreamDrawable* StreamDrawableFactory::make(const QPointF& point, Model::MOUSE_POINTER_TYPE type, const QPen& pen) {
    assert(type != Model::MOUSE_POINTER_TYPE::POINT);
    switch (type) {
        case Model::MOUSE_POINTER_TYPE::LINE:
            return new LineStream(point, pen);
            break;
        case Model::MOUSE_POINTER_TYPE::CIRCLE:
            return new CircleStream(point, pen);
            break;
        case Model::MOUSE_POINTER_TYPE::POLY_LINE:
            return new PolyLineStream(point, pen);
            break;
        default:
            assert(false);
    }
    return nullptr;
}
