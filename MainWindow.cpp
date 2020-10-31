//
// Created by pc on 27-10-20.
//

#include "MainWindow.h"

#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"
#include "View/Widgets/MainWidget.h"

MainWindow::MainWindow()
    : QMainWindow(nullptr), m_controller(new controller::Controller(this)),
      m_model(new model::Model(m_controller.get())),
      m_mainWidget(new view::MainWidget(this, m_model.get(), m_controller.get())) {
    setCentralWidget(m_mainWidget);
    m_controller->init(m_mainWidget, m_model.get());

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

    resize(1200, 900);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    m_controller->keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    m_controller->keyReleaseEvent(event);
}