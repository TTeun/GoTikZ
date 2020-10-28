//
// Created by pc on 28-10-20.
//

#include "Transform.h"

#include <QDebug>
#include <QPainter>

void Transform::setTranslation(const QPointF& translation) {
    m_translation = translation;
}

void Transform::addTranslation(const QPointF& translation) {
    m_translation += translation;
}

QPointF Transform::translation() const {
    return m_translation;
}

void Transform::applyTransform(QPainter& painter) {
    painter.translate(m_translation);
    painter.scale(m_scale, m_scale);
}

QPointF Transform::invertTransform(const QPointF& point) {
    return QPointF{point.x() / m_scale, point.y() / m_scale} - m_translation / m_scale;
}

void Transform::addToScaleParameter(double addend) {
    m_scaleParameter += addend;
    m_scale = std::pow(1.1, m_scaleParameter);
}

double Transform::scale() const {
    return m_scale;
}
