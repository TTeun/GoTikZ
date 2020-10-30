//
// Created by pc on 27-10-20.
//

#include "PrimitiveTypeEnum.h"

#include <QString>

PRIMITIVE_TYPE primitiveTypeFromString(const QString& str) {

    if (str == QString("Point")) {
        return PRIMITIVE_TYPE::POINT;
    }

    if (str == QString("Circle")) {
        return PRIMITIVE_TYPE::CIRCLE;
    }

    if (str == QString("Line")) {
        return PRIMITIVE_TYPE::LINE;
    }

    if (str == QString("PolyLine")) {
        return PRIMITIVE_TYPE::POLY_LINE;
    }

    assert(false);
    return PRIMITIVE_TYPE::POINT;
}
