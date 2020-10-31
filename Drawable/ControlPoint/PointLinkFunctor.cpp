//
// Created by pc on 30-10-20.
//

#include "PointLinkFunctor.h"

#include "Drawable/Drawable.h"
#include "Drawable/PolyLine.h"

#include <QPointF>

PointLinkFunctor::PointLinkFunctor(size_t index, Drawable* drawable) : m_index(index), m_drawable(drawable) {
    assert(m_drawable->visible());
    switch (m_drawable->type()) {
        case PRIMITIVE_TYPE::LINE:
            assert(index < 2);
            break;
        case PRIMITIVE_TYPE::POINT:
            assert(index < 1);
            break;
        case PRIMITIVE_TYPE::CIRCLE:
            assert(index < 2);
            break;
        case PRIMITIVE_TYPE::POLY_LINE:
            assert(index < dynamic_cast<PolyLine*>(m_drawable)->numberOfPoints());
            break;
        case PRIMITIVE_TYPE::STREAM:
            assert(false);
            break;
    }
}

void PointLinkFunctor::setPoint(const QPointF& newPoint) const {
    assert(m_drawable->visible());
    m_drawable->setPoint(m_index, newPoint);
}

Drawable* PointLinkFunctor::drawable() const {
    assert(m_drawable->visible());
    return m_drawable;
}

QPointF PointLinkFunctor::point() const {
    assert(m_drawable->visible());
    return m_drawable->point(m_index);
}
