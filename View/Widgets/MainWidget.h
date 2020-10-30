#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include <QWidget>

class RightSideBar;
class LeftSideBar;
namespace controller {
    class Controller;
}

namespace view {
    class LeftSideBar;
    class RightSideBar;
    class DrawWidget;
} // namespace view

namespace model {
    class Model;
}

namespace view {
    class MainWidget : public QWidget {
        Q_OBJECT

      public:
        explicit MainWidget(QWidget* parent, const model::Model* model, controller::Controller* controller);

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
} // namespace view

#endif // GOTIKZ_MAINWIDGET_H
