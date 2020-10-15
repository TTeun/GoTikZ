#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QAbstractButton>

class DrawWidget;
class LeftSideBar;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

public slots:
  void hoi(QString str);

private:
  Ui::MainWindow *ui;
  DrawWidget *m_drawWidget;
  LeftSideBar *m_leftSideBar;
};
#endif // MAINWINDOW_H
