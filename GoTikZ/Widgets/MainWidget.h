#ifndef GOTIKZ_MAINWIDGET_H
#define GOTIKZ_MAINWIDGET_H

#include <Actions/ActionHandler.h>
#include <QMainWindow>

class LeftSideBar;

class MainWidget : public QWidget {
    Q_OBJECT

  public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget() override;

    void keyPressEvent(QKeyEvent* event) override;

  private:
    std::unique_ptr<ActionHandler> m_actionHandler;
    LeftSideBar*                   m_leftSideBar;
};

#endif // GOTIKZ_MAINWIDGET_H
