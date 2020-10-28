//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_POINTEDITWIDGET_H
#define GOTIKZ_POINTEDITWIDGET_H

#include <QObject>
#include <Widgets/GroupBoxContainer.h>

class Point;
class ActionHandler;

class PointEditWidget : public QObject, public GroupBoxContainer {
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
