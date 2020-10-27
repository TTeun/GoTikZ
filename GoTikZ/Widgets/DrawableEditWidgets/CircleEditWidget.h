//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_CIRCLEEDITWIDGET_H
#define GOTIKZ_CIRCLEEDITWIDGET_H

#include "../GroupBoxContainer.h"

class Circle;
class ActionHandler;

class CircleEditWidget : public QObject, public GroupBoxContainer {

    Q_OBJECT

  public:
    explicit CircleEditWidget(Circle* circle, ActionHandler* actionHandler);

  public slots:
    void setCenter(QPointF newCenter);

  private:
    ActionHandler* m_actionHandler;
    Circle*        m_circle;
};

#endif // GOTIKZ_CIRCLEEDITWIDGET_H
