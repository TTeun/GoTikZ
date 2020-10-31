//
// Created by pc on 30-10-20.
//

#include "Drawable/ControlPoint/ControlPointFactory.h"

#include "Drawable/ControlPoint/ControlPoint.h"

void f(const QPointF& point) {
    qDebug() << point;
}

ControlPointFactory::ControlPointFactory(Drawable* drawable) : m_drawable(drawable) {
}

size_t ControlPointFactory::numberOfControlPoints() const {
    switch (m_drawable->type()) {
        case PRIMITIVE_TYPE::LINE:
            return 2;
            break;
        case PRIMITIVE_TYPE::POINT:
            return 1;
            break;
        case PRIMITIVE_TYPE::CIRCLE:
            return 2;
            break;
        case PRIMITIVE_TYPE::POLY_LINE:
            return dynamic_cast<const PolyLine*>(m_drawable)->numberOfPoints();
            break;
        case PRIMITIVE_TYPE::STREAM:
            assert(false);
            break;
    }
    return 0;
}

ControlPoint* ControlPointFactory::controlPoint(Line* line, size_t index) {
    if (index == 0) {
        return new ControlPoint(line->point1(), line->pen(), PointInterface(index, line));
    } else {
        return new ControlPoint(line->point2(), line->pen(), PointInterface(index, line));
    }
}

ControlPoint* ControlPointFactory::controlPoint(Point* point, size_t index) {
    return new ControlPoint(point->point(), point->pen(), PointInterface(index, point));
}

ControlPoint* ControlPointFactory::controlPoint(Circle* circle, size_t index) {
    if (index == 0) {
        return new ControlPoint(circle->center(), circle->pen(), PointInterface(index, circle));
    } else {
        return new ControlPoint(circle->center() + QPointF{circle->radius(), 0}, circle->pen(),
                                PointInterface(index, circle));
    }
}

ControlPoint* ControlPointFactory::controlPoint(PolyLine* polyLine, size_t index) {
    return new ControlPoint(polyLine->points().at(index), polyLine->pen(), PointInterface(index, polyLine));
}

ControlPoint* ControlPointFactory::controlPoint(size_t index) const {
    assert(index < numberOfControlPoints());
    switch (m_drawable->type()) {

        case PRIMITIVE_TYPE::LINE:
            return controlPoint(dynamic_cast<Line*>(m_drawable), index);
        case PRIMITIVE_TYPE::POINT:
            return controlPoint(dynamic_cast<Point*>(m_drawable), index);
        case PRIMITIVE_TYPE::CIRCLE:
            return controlPoint(dynamic_cast<Circle*>(m_drawable), index);
        case PRIMITIVE_TYPE::POLY_LINE:
            return controlPoint(dynamic_cast<PolyLine*>(m_drawable), index);
        case PRIMITIVE_TYPE::STREAM:
            break;
    }
    assert(false);
    return nullptr;
}
