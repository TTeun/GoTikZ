//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_POINTEDITWIDGET_H
#define GOTIKZ_POINTEDITWIDGET_H

#include "Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

class Point;
class ActionHandler;

class PointEditWidget : public QWidget, public GroupBoxContainer {
    Q_OBJECT

  public:
    PointEditWidget(Point* point, ActionHandler* actionHandler);

  public slots:
    void setPoint(QPointF newPoint);

  private:
    ActionHandler* m_actionHandler;
    Point*         m_point;
};

#endif // GOTIKZ_POINTEDITWIDGET_H
