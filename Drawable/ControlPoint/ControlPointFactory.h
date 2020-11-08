//
// Created by pc on 30-10-20.
//

#ifndef GOTIKZ_CONTROLPOINTFACTORY_H
#define GOTIKZ_CONTROLPOINTFACTORY_H

#include "Drawable/Circle.h"
#include "Drawable/Line.h"
#include "Drawable/Point.h"
#include "Drawable/PolyLine.h"

class ControlPointFactory {
  public:
    explicit ControlPointFactory(Drawable* drawable);

    size_t        numberOfControlPoints() const;
    ControlPoint* controlPoint(size_t index) const;

  private:
    static ControlPoint* controlPoint(Line* line, size_t index);
    static ControlPoint* controlPoint(Point* point, size_t index);
    static ControlPoint* controlPoint(Circle* circle, size_t index);
    static ControlPoint* controlPoint(PolyLine* polyLine, size_t index);

    Drawable* m_drawable;
};

#endif // GOTIKZ_CONTROLPOINTFACTORY_H
