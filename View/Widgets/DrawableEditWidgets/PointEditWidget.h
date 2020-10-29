//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_POINTEDITWIDGET_H
#define GOTIKZ_POINTEDITWIDGET_H

#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"

class Point;

namespace View {
    class XyWidget;
}

namespace Controller {
    class ActionHandler;
}

class PointEditWidget : public View::DrawableEditWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    PointEditWidget(Point* point, Controller::ActionHandler* actionHandler);

  public slots:
    void setPoint(QPointF newPoint);
    void needsUpdate() override;

  private:
    View::XyWidget*            m_point1Widget;
    Controller::ActionHandler* m_actionHandler;
    Point*                     m_point;
};

#endif // GOTIKZ_POINTEDITWIDGET_H
