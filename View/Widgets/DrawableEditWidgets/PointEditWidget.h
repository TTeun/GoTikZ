//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_POINTEDITWIDGET_H
#define GOTIKZ_POINTEDITWIDGET_H

#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"

class Point;

namespace view {
    class XyWidget;
}

namespace controller {
    class Controller;
}

class PointEditWidget : public view::DrawableEditWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    PointEditWidget(Point* point, controller::Controller* controller);

  public slots:
    void setPoint(QPointF newPoint);
    void needsUpdate() override;

  private:
    view::XyWidget*            m_point1Widget;
    controller::Controller* m_controller;
    Point*                     m_point;
};

#endif // GOTIKZ_POINTEDITWIDGET_H
