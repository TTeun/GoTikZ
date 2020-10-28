//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_CIRCLEEDITWIDGET_H
#define GOTIKZ_CIRCLEEDITWIDGET_H

#include "Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

class Circle;
class QSpinBox;
class XyWidget;
class ActionHandler;

class CircleEditWidget : public QWidget, public GroupBoxContainer {

    Q_OBJECT

  public:
    CircleEditWidget(Circle* circle, ActionHandler* actionHandler);
    ~CircleEditWidget();

  public slots:
    void setCenter(QPointF newCenter);
    void setRadius(double newRadius);
    void needsUpdate();

  private:
    QSpinBox* m_radiusSpinBox;
    XyWidget* m_centerWidget;

    ActionHandler* m_actionHandler;
    Circle*        m_circle;
};

#endif // GOTIKZ_CIRCLEEDITWIDGET_H
