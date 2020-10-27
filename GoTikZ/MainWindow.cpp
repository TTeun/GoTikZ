//
// Created by pc on 27-10-20.
//

#include "MainWindow.h"

#include "Widgets/GridSettingWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/PenWidget.h"
#include "Widgets/PrimitiveSelectWidget.h"

#include <QKeyEvent>

MainWindow::MainWindow() : QMainWindow(nullptr), m_actionHandler(this), m_mainWidget(new MainWidget(this)) {
    setCentralWidget(m_mainWidget);
    m_actionHandler.init(m_mainWidget->drawWidget(), m_mainWidget->leftSideBar());

    resize(800, 600);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->modifiers()) {
        case Qt::NoModifier:
            switch (event->key()) {
                case Qt::Key_P:
                    m_mainWidget->leftSideBar()->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::POINT);
                    break;
                case Qt::Key_L:
                    m_mainWidget->leftSideBar()->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::LINE);
                    break;
                case Qt::Key_C:
                    m_mainWidget->leftSideBar()->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::CIRCLE);
                    break;
                case Qt::Key_Y:
                    m_mainWidget->leftSideBar()->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::POLY_LINE);
                    break;
            }

            break;
        case Qt::ControlModifier:
            switch (event->key()) {
                case Qt::Key_Z:
                    m_actionHandler.undoAction();
                    break;
                case Qt::Key_R:
                    m_actionHandler.redoAction();
                    break;
                default:
                    break;
            }
            break;
    }
}
