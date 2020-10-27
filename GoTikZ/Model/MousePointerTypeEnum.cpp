//
// Created by pc on 27-10-20.
//

#include "MousePointerTypeEnum.h"

#include <QString>

MOUSE_POINTER_TYPE mousePointerTypeFromString(const QString& str) {

    if (str == QString("Point")) {
        return MOUSE_POINTER_TYPE::POINT;
    }

    if (str == QString("Circle")) {
        return MOUSE_POINTER_TYPE::CIRCLE;
    }

    if (str == QString("Line")) {
        return MOUSE_POINTER_TYPE::LINE;
    }

    if (str == QString("PolyLine")) {
        return MOUSE_POINTER_TYPE::POLY_LINE;
    }

    if (str == QString("Select")) {
        return MOUSE_POINTER_TYPE::SELECT;
    }

    assert(false);
}
