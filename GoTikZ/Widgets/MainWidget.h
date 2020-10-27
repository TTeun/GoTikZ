#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include <QWidget>

class RightSideBar;
class LeftSideBar;
class ActionHandler;
class DrawWidget;
class Model;

class MainWidget : public QWidget {
    Q_OBJECT

  public:
    explicit MainWidget(QWidget* parent, Model* model, ActionHandler* actionHandler);
    ~MainWidget() override;

    DrawWidget* drawWidget() {
        return m_drawWidget;
    }

    LeftSideBar* leftSideBar() {
        return m_leftSideBar;
    }

    RightSideBar* rightSideBar() {
        return m_rightSideBar;
    }

  private:
    RightSideBar* m_rightSideBar;
    LeftSideBar*  m_leftSideBar;
    DrawWidget*   m_drawWidget;
};

#endif // GOTIKZ_MAINWIDGET_H
