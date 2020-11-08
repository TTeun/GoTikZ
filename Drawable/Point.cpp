//
// Created by pc on 15-10-20.
//

#include "Point.h"

#include "Controller/CoordinateConverter.h"
#include "View/Widgets/DrawableEditWidgets/PointEditWidget.h"

#include <Math/Math.h>
#include <QPainter>

void Point::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                 const controller::CoordinateConverter& coordinateConverter) const {
    Drawable::draw(painter, drawFlag, coordinateConverter);
    painter->drawPoint(coordinateConverter.worldToScreen(m_point));
}

std::pair<double, QPointF> Point::snap(const QPointF& point) const {
    assert(m_isVisible);
    return {math::magnitude(point - m_point), m_point};
}

double Point::dist(const QPointF& point) const {
    assert(m_isVisible);
    return math::distance(point, m_point);
}

void Point::setPoint(const QPointF& newPoint) {
    assert(m_isVisible);
    m_point = newPoint;
}

QPointF Point::point() const {
    assert(m_isVisible);
    return m_point;
}

void Point::translate(const QPointF& translation) {
    assert(m_isVisible);
    m_point += translation;
}

PRIMITIVE_TYPE Point::type() const {
    assert(m_isVisible);
    return PRIMITIVE_TYPE::POINT;
}

void Point::setPoint(size_t index, const QPointF& point) {
    assert(m_isVisible);
    m_point = point;
}

QPointF Point::point(size_t index) const {
    assert(m_isVisible);
    return m_point;
}
