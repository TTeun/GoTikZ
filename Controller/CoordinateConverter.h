//
// Created by pc on 31-10-20.
//

#ifndef GOTIKZ_COORDINATECONVERTER_H
#define GOTIKZ_COORDINATECONVERTER_H

#include <QPointF>

class DrawableHandler;

namespace view {
    class Transform;
}

namespace controller {
    class CoordinateConverter {
      public:
        CoordinateConverter(const view::Transform* transform, const DrawableHandler* drawableHandler);

        QPointF screenToWorld(const QPointF& screenPoint) const;
        QPointF worldToScreen(const QPointF& worldPoint) const;
        QPointF snapScreen(const QPointF& worldPoint) const;

        double scale(const double value) const;

      private:
        const view::Transform* m_transform;
        const DrawableHandler* m_drawableHandler;
    };
} // namespace controller

#endif // GOTIKZ_COORDINATECONVERTER_H
