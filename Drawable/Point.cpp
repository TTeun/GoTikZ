//
// Created by pc on 15-10-20.
//

#include "Point.h"

#include "View/Transform.h"
#include "View/Widgets/DrawableEditWidgets/PointEditWidget.h"

#include <Math/Math.h>
#include <QPainter>

void Point::draw(QPainter* painter, DRAW_FLAGS drawFlag, const View::Transform& transform) const {
    Drawable::draw(painter, drawFlag, transform);
    painter->drawPoint(transform.applyTransform(m_point));
}

std::pair<double, QPointF> Point::snap(QPointF point) {
    return {Math::magnitude(point - m_point), m_point};
}

double Point::dist(const QPointF& point) const {
    return Math::distance(point, m_point);
}

void Point::setPoint(const QPointF& newPoint) {
    m_point = newPoint;
}

QPointF Point::point() const {
    return m_point;
}

QWidget* Point::toWidget(Controller::ActionHandler* actionHandler) {
    return new PointEditWidget(this, actionHandler);
}

void Point::translate(const QPointF& translation) {
    m_point += translation;
}
