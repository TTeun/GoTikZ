//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MAINWINDOW_H
#define GOTIKZ_MAINWINDOW_H

#include "Controller/Controller.h"
#include "Model/Model.h"

#include <QMainWindow>
#include <memory>

namespace view {
    class MainWidget;
}

namespace model {
    class Model;
}

namespace controller {
    class Controller;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

  public:
    MainWindow();

    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

  private:
    std::unique_ptr<controller::Controller> m_controller;
    std::unique_ptr<model::Model>       m_model;
    view::MainWidget*                          m_mainWidget;
};

#endif // GOTIKZ_MAINWINDOW_H
