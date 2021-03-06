//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_CIRCLEEDITWIDGET_H
#define GOTIKZ_CIRCLEEDITWIDGET_H

#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"
#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"

class Circle;
class QSpinBox;

namespace controller {
    class Controller;
}

namespace view {
    class XyWidget;

    class CircleEditWidget : public DrawableEditWidget, public GroupBoxContainer {

        Q_OBJECT

      public:
        CircleEditWidget(Circle* circle, controller::Controller* controller);

      public slots:
        void setCenter(QPointF newCenter);
        void setRadius(double newRadius);
        void needsUpdate() override;

      private:
        QSpinBox* m_radiusSpinBox;
        XyWidget* m_centerWidget;

        controller::Controller* m_controller;
        Circle*                 m_circle;
    };
} // namespace view

namespace controller {
    class Controller;
}

#endif // GOTIKZ_CIRCLEEDITWIDGET_H
