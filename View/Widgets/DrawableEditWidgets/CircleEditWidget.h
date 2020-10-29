//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_CIRCLEEDITWIDGET_H
#define GOTIKZ_CIRCLEEDITWIDGET_H

#include "View/Widgets/DrawableEditWidgets/DrawableEditWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

class Circle;
class QSpinBox;

namespace Controller {
    class ActionHandler;
}

namespace View {
    class XyWidget;

    class CircleEditWidget : public DrawableEditWidget, public GroupBoxContainer {

        Q_OBJECT

      public:
        CircleEditWidget(Circle* circle, Controller::ActionHandler* actionHandler);
        ~CircleEditWidget();

      public slots:
        void setCenter(QPointF newCenter);
        void setRadius(double newRadius);
        void needsUpdate() override;

      private:
        QSpinBox* m_radiusSpinBox;
        XyWidget* m_centerWidget;

        Controller::ActionHandler* m_actionHandler;
        Circle*                    m_circle;
    };
} // namespace View

namespace Controller {
    class ActionHandler;
}

#endif // GOTIKZ_CIRCLEEDITWIDGET_H
