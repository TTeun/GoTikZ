//
// Created by pc on 31-10-20.
//

#include "CoordinateConverter.h"

#include "Drawable/DrawableHandler.h"
#include "View/Transform.h"

controller::CoordinateConverter::CoordinateConverter(const view::Transform* transform,
                                                     const DrawableHandler* drawableHandler)
    : m_transform(transform), m_drawableHandler(drawableHandler) {
}

QPointF controller::CoordinateConverter::worldToScreen(const QPointF& worldPoint) const {
    return m_transform->applyTransform(worldPoint);
}

QPointF controller::CoordinateConverter::screenToWorld(const QPointF& screenPoint) const {
    return m_transform->invertTransform(screenPoint);
}

QPointF controller::CoordinateConverter::snapScreen(const QPointF& screenPoint,
                                                    const double   maximumSnapScreenDistance) const {
    return worldToScreen(
        m_drawableHandler->snap(screenToWorld(screenPoint), screenToWorldDistance(maximumSnapScreenDistance)));
}

double controller::CoordinateConverter::worldToScreenDistance(const double value) const {
    return m_transform->scale() * value;
}

double controller::CoordinateConverter::screenToWorldDistance(const double value) const {
    return value / m_transform->scale();
}

QPointF controller::CoordinateConverter::screenToWorldSnap(const QPointF& screenPoint,
                                                           const double   maximumSnapScreenDistance) const {
    return m_drawableHandler->snap(screenToWorld(screenPoint), screenToWorldDistance(maximumSnapScreenDistance));
}
