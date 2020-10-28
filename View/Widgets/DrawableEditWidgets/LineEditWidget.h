//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_LINEEDITWIDGET_H
#define GOTIKZ_LINEEDITWIDGET_H

#include "Controller/Actions/ActionHandler.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

class Line;
namespace Controller {
class ActionHandler;
}

class LineEditWidget : public QWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    LineEditWidget(Line* line, Controller::ActionHandler* actionHandler);

  public slots:
    void setPoint1(QPointF newPoint);
    void setPoint2(QPointF newPoint);

  private:
    Line*                      m_line;
    Controller::ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_LINEEDITWIDGET_H
