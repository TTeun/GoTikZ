#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include "Actions/ActionHandler.h"

#include <QWidget>

class LeftSideBar;
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

  private:
    LeftSideBar* m_leftSideBar;
    DrawWidget*  m_drawWidget;
};

#endif // GOTIKZ_MAINWIDGET_H
