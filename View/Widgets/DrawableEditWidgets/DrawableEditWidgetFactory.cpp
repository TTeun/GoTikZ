//
// Created by pc on 29-10-20.
//

#include "DrawableEditWidgetFactory.h"

#include "Drawable/Circle.h"
#include "Drawable/Line.h"
#include "Drawable/Point.h"
#include "Drawable/PolyLine.h"
#include "View/Widgets/DrawableEditWidgets/CircleEditWidget.h"
#include "View/Widgets/DrawableEditWidgets/LineEditWidget.h"
#include "View/Widgets/DrawableEditWidgets/PointEditWidget.h"

QWidget* view::DrawableEditWidgetFactory::create(PRIMITIVE_TYPE type, Drawable* drawable,
                                                 controller::Controller* controller) {
    switch (drawable->type()) {
        case PRIMITIVE_TYPE::LINE:
            return DrawableEditWidgetFactory::create(dynamic_cast<Line*>(drawable), controller);
        case PRIMITIVE_TYPE::POINT:
            return DrawableEditWidgetFactory::create(dynamic_cast<Point*>(drawable), controller);
        case PRIMITIVE_TYPE::CIRCLE:
            return DrawableEditWidgetFactory::create(dynamic_cast<Circle*>(drawable), controller);
        case PRIMITIVE_TYPE::POLY_LINE:
            return view::DrawableEditWidgetFactory::create(dynamic_cast<PolyLine*>(drawable), controller);
        case PRIMITIVE_TYPE::STREAM:
            assert(false);
    }
    return nullptr;
}

QWidget* view::DrawableEditWidgetFactory::create(Point* point, controller::Controller* controller) {
    return new PointEditWidget(point, controller);
}

QWidget* view::DrawableEditWidgetFactory::create(Line* line, controller::Controller* controller) {
    return new LineEditWidget(line, controller);
}

QWidget* view::DrawableEditWidgetFactory::create(Circle* circle, controller::Controller* controller) {
    return new CircleEditWidget(circle, controller);
}

QWidget* view::DrawableEditWidgetFactory::create(PolyLine* polyLine, controller::Controller* controller) {
    return new QWidget;
}
