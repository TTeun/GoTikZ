//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_LINEEDITWIDGET_H
#define GOTIKZ_LINEEDITWIDGET_H

#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

class Line;
namespace controller {
    class Controller;
}

namespace view {
    class XyWidget;
}

class LineEditWidget : public view::DrawableEditWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    LineEditWidget(Line* line, controller::Controller* actionHandler);

  public slots:
    void setPoint1(QPointF newPoint);
    void setPoint2(QPointF newPoint);
    void needsUpdate() override;

  private:
    view::XyWidget* m_point1Widget;
    view::XyWidget* m_point2Widget;

    Line*                      m_line;
    controller::Controller* m_actionHandler;
};

#endif // GOTIKZ_LINEEDITWIDGET_H
