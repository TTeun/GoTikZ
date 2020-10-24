#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Actions/ActionHandler.h>
#include <QMainWindow>

class LeftSideBar;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void keyPressEvent(QKeyEvent* event) override;

  private:
    std::unique_ptr<ActionHandler> m_actionHandler;
    LeftSideBar*                   m_leftSideBar;
};
#endif // MAINWINDOW_H
