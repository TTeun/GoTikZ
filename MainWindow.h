//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MAINWINDOW_H
#define GOTIKZ_MAINWINDOW_H

#include "Controller/Actions/ActionHandler.h"
#include "Model/ModelHandler.h"

#include <QMainWindow>
#include <memory>

namespace View {
    class MainWidget;
}

namespace Model {
    class ModelHandler;
}

namespace Controller {
    class ActionHandler;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

  public:
    MainWindow();

    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

  private:
    std::unique_ptr<Controller::ActionHandler> m_actionHandler;
    std::unique_ptr<Model::ModelHandler>       m_modelHandler;
    View::MainWidget*                          m_mainWidget;
};

#endif // GOTIKZ_MAINWINDOW_H
