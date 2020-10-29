#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include <QWidget>

class RightSideBar;
class LeftSideBar;
namespace Controller {
    class ActionHandler;
}

namespace View {
    class LeftSideBar;
    class RightSideBar;
    class DrawWidget;
} // namespace View

namespace Model {
    class ModelHandler;
}

namespace View {
    class MainWidget : public QWidget {
        Q_OBJECT

      public:
        explicit MainWidget(QWidget* parent, const Model::ModelHandler* model,
                            Controller::ActionHandler* actionHandler);

        DrawWidget*         drawWidget();
        LeftSideBar*        leftSideBar();
        RightSideBar*       rightSideBar();
        const DrawWidget*   drawWidget() const;
        const LeftSideBar*  leftSideBar() const;
        const RightSideBar* rightSideBar() const;

      private:
        RightSideBar* m_rightSideBar;
        LeftSideBar*  m_leftSideBar;
        DrawWidget*   m_drawWidget;
    };
} // namespace View

#endif // GOTIKZ_MAINWIDGET_H
