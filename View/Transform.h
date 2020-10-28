//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_TRANSFORM_H
#define GOTIKZ_TRANSFORM_H

#include <QPointF>
#include <cmath>

class QPainter;

namespace View {
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
        double  m_scale          = pow(1.1, m_scaleParameter);
        QPointF m_translation    = {0, 0};
    };
} // namespace View

#endif // GOTIKZ_TRANSFORM_H
