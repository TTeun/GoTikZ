//
// Created by pc on 28-10-20.
//

#ifndef GOTIKZ_TRANSFORM_H
#define GOTIKZ_TRANSFORM_H

#include <QPointF>

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
        double  m_scaleParameter = 0.0;
        double  m_scale          = 1.0;
        QPointF m_translation    = {0, 0};
    };
} // namespace View

#endif // GOTIKZ_TRANSFORM_H
