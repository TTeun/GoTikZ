//
// Created by pc on 30-10-20.
//

#include "PointSetFunctor.h"

#include "Drawable/Drawable.h"
#include "Drawable/PolyLine.h"

#include <QDebug>
#include <QPointF>

PointSetFunctor::PointSetFunctor(size_t index, Drawable* drawable) : m_index(index), m_drawable(drawable) {
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
    qDebug() << m_drawable;
}

void PointSetFunctor::setPoint(const QPointF& newPoint) const {
    m_drawable->setPoint(m_index, newPoint);
}

Drawable* PointSetFunctor::drawable() const {
    return m_drawable;
}

QPointF PointSetFunctor::point() const {
    return m_drawable->point(m_index);
}
