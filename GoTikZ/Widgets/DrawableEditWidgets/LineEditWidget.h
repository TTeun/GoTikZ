//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_LINEEDITWIDGET_H
#define GOTIKZ_LINEEDITWIDGET_H

#include "Widgets/GroupBoxContainer.h"

#include <QObject>

class Line;
class ActionHandler;

class LineEditWidget : public QObject, public GroupBoxContainer {
    Q_OBJECT

  public:
    LineEditWidget(Line* line, ActionHandler* actionHandler);

  public slots:
    void setPoint1(QPointF newPoint);
    void setPoint2(QPointF newPoint);

  private:
    Line*          m_line;
    ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_LINEEDITWIDGET_H
