//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_POINTEDITWIDGET_H
#define GOTIKZ_POINTEDITWIDGET_H

#include "Controller/Actions/ActionHandler.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

class Point;
namespace Controller {
class ActionHandler;
}
class PointEditWidget : public QWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    PointEditWidget(Point* point, Controller::ActionHandler* actionHandler);

  public slots:
    void setPoint(QPointF newPoint);

  private:
    Controller::ActionHandler* m_actionHandler;
    Point*                     m_point;
};

#endif // GOTIKZ_POINTEDITWIDGET_H
