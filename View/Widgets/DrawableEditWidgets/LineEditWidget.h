//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_LINEEDITWIDGET_H
#define GOTIKZ_LINEEDITWIDGET_H

#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

class Line;
namespace Controller {
    class ActionHandler;
}

namespace View {
    class XyWidget;
}

class LineEditWidget : public View::DrawableEditWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    LineEditWidget(Line* line, Controller::ActionHandler* actionHandler);

  public slots:
    void setPoint1(QPointF newPoint);
    void setPoint2(QPointF newPoint);
    void needsUpdate() override;

  private:
    View::XyWidget* m_point1Widget;
    View::XyWidget* m_point2Widget;

    Line*                      m_line;
    Controller::ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_LINEEDITWIDGET_H
