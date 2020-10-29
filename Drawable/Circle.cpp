//
// Created by pc on 15-10-20.
//

#include "Circle.h"

#include "CircleStream.h"
#include "Math/Math.h"
#include "View/Transform.h"
#include "View/Widgets/DrawableEditWidgets/CircleEditWidget.h"

#include <QPainter>

Circle::Circle(const CircleStream& circleStream)
    : Drawable(circleStream.m_pen), m_center(circleStream.m_center), m_radius(circleStream.m_radius) {
}

void Circle::draw(QPainter* painter, DRAW_FLAGS drawFlag, const View::Transform& transform) const {
    Drawable::draw(painter, drawFlag, transform);
    painter->drawEllipse(transform.applyTransform(m_center), m_radius * transform.scale(),
                         m_radius * transform.scale());
}

std::pair<double, QPointF> Circle::snap(QPointF point) {
    const auto difference = point - m_center;
    const auto closest    = m_center + m_radius * difference / Math::magnitude(difference);

    return {Math::magnitude(point - closest), closest};
}

double Circle::dist(const QPointF& point) const {
    const double distToCenter = Math::distance(point, m_center);
    return std::abs(distToCenter - m_radius);
}

QWidget* Circle::toWidget(Controller::ActionHandler* actionHandler) {
    return new View::CircleEditWidget(this, actionHandler);
}

QPointF Circle::center() const {
    return m_center;
}

double Circle::radius() const {
    return m_radius;
}

void Circle::setCenter(const QPointF& newCenter) {
    m_center = newCenter;
}

void Circle::setRadius(double newRadius) {
    m_radius = newRadius;
}
void Circle::translate(const QPointF& translation) {
    m_center += translation;
}
