        //
// Created by pc on 27-10-20.
//

#include "MainWindow.h"

#include "Widgets/AuxWidgets/GroupBoxContainer.h"

        MainWindow::MainWindow()
    : QMainWindow(nullptr), m_actionHandler(this), m_model(&m_actionHandler),
      m_mainWidget(new MainWidget(this, &m_model, &m_actionHandler)) {
    setCentralWidget(m_mainWidget);
    m_actionHandler.init(m_mainWidget,
                         &m_model);



    setStyleSheet(
                "QGroupBox{"
                "   background-color: rgb(123,255,255);"
                "   border: 1px solid gray;"
                "   border-radius: 2px;"
                "   padding-top: 3ex;"
                "}"
                "QLabel{"
                "   background-color: rgb(23,255,255);"
                "}"
                  );

    resize(800, 600);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    m_actionHandler.keyPressEvent(event);
}
