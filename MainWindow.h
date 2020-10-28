//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MAINWINDOW_H
#define GOTIKZ_MAINWINDOW_H

#include "Actions/ActionHandler.h"
#include "Model/Model.h"
#include "Widgets/MainWidget.h"

#include <QMainWindow>

class MainWindow : public QMainWindow {

    Q_OBJECT

  public:
    MainWindow();

    void keyPressEvent(QKeyEvent* event) override;

  private:
    ActionHandler m_actionHandler;
    Model         m_model;
    MainWidget*   m_mainWidget;
};

#endif // GOTIKZ_MAINWINDOW_H
