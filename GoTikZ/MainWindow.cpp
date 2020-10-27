//
// Created by pc on 27-10-20.
//

#include "MainWindow.h"

MainWindow::MainWindow()
    : QMainWindow(nullptr), m_actionHandler(this), m_model(&m_actionHandler),
      m_mainWidget(new MainWidget(this, &m_model, &m_actionHandler)) {
    setCentralWidget(m_mainWidget);
    m_actionHandler.init(m_mainWidget->drawWidget(), m_mainWidget->leftSideBar(), m_mainWidget->rightSideBar(),
                         &m_model);

    resize(800, 600);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    m_actionHandler.keyPressEvent(event);
}
