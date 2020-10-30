//
// Created by pc on 29-10-20.
//

#include "ControlPoint.h"

#include "View/Transform.h"

#include <QPainter>

ControlPoint::ControlPoint(const QPointF& point, const QPen& pen, const PointSetFunctor pointSetFunctor)
    : Point(point, pen), m_pointSetFunctor(pointSetFunctor) {
    m_pen.setColor(Qt::darkGray);
    m_pen.setWidth(2);
}

void ControlPoint::draw(QPainter* painter, Drawable::DRAW_FLAGS drawFlag, const view::Transform& transform) const {
    painter->save();
    painter->setPen(m_pen);

    const auto point = transform.applyTransform(m_point);
    const auto width = m_pen.width() + 5;

    //    const auto x     = point.x();
    //    const auto y     = point.y();
    //    painter->drawLine(x - width, y - width, x - width, y + width);
    //    painter->drawLine(x + width, y - width, x + width, y + width);

    //    painter->drawLine(x - width, y - width, x + width, y - width);
    //    painter->drawLine(x - width, y + width, x + width, y + width);

    painter->drawEllipse(point, width, width);

    painter->restore();
}

void ControlPoint::translate(const QPointF& translation) {
    Point::translate(translation);
    m_pointSetFunctor.setPoint(m_point);
}

Drawable* ControlPoint::drawable() const {
    return m_pointSetFunctor.drawable();
}

void ControlPoint::update() {
    m_point = m_pointSetFunctor.point();
}
