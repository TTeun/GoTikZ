//
// Created by pc on 29-10-20.
//

#include "ControlPoint.h"

#include "View/ColorPresets.h"
#include "View/Transform.h"

#include <QPainter>

ControlPoint::ControlPoint(const QPointF& point, const QPen& pen, const PointLinkFunctor pointSetFunctor)
    : Point(point, pen), m_pointLinkFunctor(pointSetFunctor) {
    m_pen.setColor(ColorPresets::s_controlPointColor);
    m_pen.setWidth(2);
}

void ControlPoint::draw(QPainter* painter, Drawable::DRAW_FLAGS drawFlag, const view::Transform& transform) const {
    painter->save();
    painter->setPen(m_pen);

    const auto point = transform.applyTransform(m_point);
    const auto width = m_pen.width() + (m_isHighlighted ? 8 : 4);

    const auto x = point.x();
    const auto y = point.y();
    painter->drawLine(x - width, y - width, x - width, y + width);
    painter->drawLine(x + width, y - width, x + width, y + width);

    painter->drawLine(x - width, y - width, x + width, y - width);
    painter->drawLine(x - width, y + width, x + width, y + width);

    painter->drawEllipse(point, width - 2, width - 2);

    painter->restore();
}

void ControlPoint::translate(const QPointF& translation) {
    Point::translate(translation);
    m_pointLinkFunctor.setPoint(m_point);
}

Drawable* ControlPoint::drawable() const {
    return m_pointLinkFunctor.drawable();
}

void ControlPoint::update() {
    m_point = m_pointLinkFunctor.point();
}

void ControlPoint::setHighlighted(bool highlighted) {
    m_isHighlighted = highlighted;
}
