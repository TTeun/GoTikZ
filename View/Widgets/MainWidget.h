#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include "Controller/Actions/ActionHandler.h"
#include "DrawWidget.h"
#include "LeftSideBar.h"
#include "RightSideBar.h"

#include <QWidget>

class RightSideBar;
class LeftSideBar;
namespace Controller {
    class ActionHandler;
}
class DrawWidget;
class Model;

namespace View {
    class MainWidget : public QWidget {
        Q_OBJECT

      public:
        explicit MainWidget(QWidget* parent, Model* model, Controller::ActionHandler* actionHandler);
        ~MainWidget() override;

        DrawWidget* drawWidget();

        LeftSideBar* leftSideBar();

        RightSideBar* rightSideBar();

      private:
        RightSideBar* m_rightSideBar;
        LeftSideBar*  m_leftSideBar;
        DrawWidget*   m_drawWidget;
    };
} // namespace View

#endif // GOTIKZ_MAINWIDGET_H
