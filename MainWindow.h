//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MAINWINDOW_H
#define GOTIKZ_MAINWINDOW_H

#include "Controller/Actions/ActionHandler.h"
#include "Model/Model.h"

#include <QMainWindow>

namespace View {
    class MainWidget;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

  public:
    MainWindow();

    void keyPressEvent(QKeyEvent* event) override;

  private:
    Controller::ActionHandler m_actionHandler;
    Model                     m_model;
    View::MainWidget*         m_mainWidget;
};

#endif // GOTIKZ_MAINWINDOW_H
