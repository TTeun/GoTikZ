//
// Created by pc on 27-10-20.
//

#include "MainWindow.h"

#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"
#include "View/Widgets/MainWidget.h"

MainWindow::MainWindow()
    : QMainWindow(nullptr), m_actionHandler(new Controller::ActionHandler(this)),
      m_modelHandler(new Model::ModelHandler(m_actionHandler.get())),
      m_mainWidget(new View::MainWidget(this, m_modelHandler.get(), m_actionHandler.get())) {
    setCentralWidget(m_mainWidget);
    m_actionHandler->init(m_mainWidget, m_modelHandler.get());

    setStyleSheet("QGroupBox{"
                  "   background-color: rgb(123,255,255);"
                  "   border: 1px solid gray;"
                  "   border-radius: 2px;"
                  "   padding-top: 3ex;"
                  "}"
                  "LeftSideBar{"
                  "   border: 1px solid gray;"
                  "   border-radius: 2px;"
                  "   padding-top: 3ex;"
                  "}"
                  "QLabel{"
                  "   background-color: rgb(23,255,255);"
                  "}");

    resize(800, 600);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    m_actionHandler->keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    m_actionHandler->keyReleaseEvent(event);
}