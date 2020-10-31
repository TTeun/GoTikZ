//
// Created by pc on 29-10-20.
//

#include "ControlPoint.h"

#include "Controller/CoordinateConverter.h"
#include "View/ColorPresets.h"

#include <QPainter>

ControlPoint::ControlPoint(const QPointF& point, const QPen& pen, const PointInterface pointSetFunctor)
    : Point(point, pen), m_pointInterface(pointSetFunctor) {
    m_pen.setColor(ColorPresets::s_controlPointColor);
    m_pen.setWidth(2);
}

void ControlPoint::draw(QPainter* painter, Drawable::DRAW_FLAGS drawFlag,
                        const controller::CoordinateConverter& coordinateConverter) const {
    painter->save();
    painter->setPen(m_pen);

    const auto point = coordinateConverter.worldToScreen(m_point);
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
    m_pointInterface.setPoint(m_point);
}

Drawable* ControlPoint::drawable() const {
    return m_pointInterface.drawable();
}

void ControlPoint::update() {
    m_isVisible = drawable()->visible();
    if (not m_isVisible) {
        return;
    }
    m_point = m_pointInterface.point();
}

void ControlPoint::setHighlighted(bool highlighted) {
    m_isHighlighted = highlighted;
}
