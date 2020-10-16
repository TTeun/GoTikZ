#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Actions/ActionHandler.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::MainWindow* ui;

    std::unique_ptr<ActionHandler> m_actionHandler;
};
#endif // MAINWINDOW_H
