//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_TRANSFORM_H
#define GOTIKZ_TRANSFORM_H

#include <QPointF>
#include <cmath>

class QPainter;

class Transform {
  public:
    void    setTranslation(const QPointF& translation);
    void    addTranslation(const QPointF& translation);
    QPointF translation() const;
    void    addToScaleParameter(double addend);
    QPointF applyTransform(QPointF point) const;
    QPointF invertTransform(const QPointF& point) const;
    double  scale() const;

  private:
    double  m_scaleParameter = 0;
    double  m_scale          = std::pow(1.1, m_scaleParameter);
    QPointF m_translation    = {0, 0};
};

#endif // GOTIKZ_TRANSFORM_H
