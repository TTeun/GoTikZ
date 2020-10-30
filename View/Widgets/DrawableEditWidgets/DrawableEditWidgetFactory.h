//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_DRAWABLEEDITWIDGETFACTORY_H
#define GOTIKZ_DRAWABLEEDITWIDGETFACTORY_H

#include "Model/PrimitiveTypeEnum.h"

class QWidget;
class Point;
class Line;
class Circle;
class PolyLine;
class Drawable;

namespace controller {
    class Controller;
}

namespace view {
    class DrawableEditWidgetFactory {
      public:
        static QWidget* create(PRIMITIVE_TYPE type, Drawable* drawable, controller::Controller* controller);

      private:
        static QWidget* create(Point* point, controller::Controller* controller);
        static QWidget* create(Line* point, controller::Controller* controller);
        static QWidget* create(Circle* point, controller::Controller* controller);
        static QWidget* create(PolyLine* point, controller::Controller* controller);
    };
} // namespace view

#endif // GOTIKZ_DRAWABLEEDITWIDGETFACTORY_H
