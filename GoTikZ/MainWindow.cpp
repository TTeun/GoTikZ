#include "MainWindow.h"

#include "Actions/ChangePrimitiveAction.h"
#include "Widgets/ColorWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/PrimitiveSelectWidget.h"

#include <QKeyEvent>
#include <QtWidgets/QHBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {

    auto* drawWidget = new DrawWidget(this);

    m_leftSideBar = new LeftSideBar(this);
    m_leftSideBar->resize(200, 800);
    layout()->addWidget(m_leftSideBar);
    m_actionHandler = std::make_unique<ActionHandler>(drawWidget, m_leftSideBar);

    QObject::connect(drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QMainWindow::*)(void)>(&QMainWindow::update));
    setCentralWidget(drawWidget);
    m_actionHandler->init();
    resize(800, 600);
}

MainWindow::~MainWindow() {
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->modifiers()) {
        case Qt::NoModifier:
            //            switch (event->key()) {
            //                case Qt::Key_P:
            //                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
            //                        DrawWidget::PRIMITIVE_TYPE::POINT);
            //                    break;
            //                case Qt::Key_L:
            //                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
            //                        DrawWidget::PRIMITIVE_TYPE::LINE);
            //                    break;
            //                case Qt::Key_C:
            //                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
            //                        DrawWidget::PRIMITIVE_TYPE::CIRCLE);
            //                    break;
            //                case Qt::Key_Y:
            //                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
            //                        DrawWidget::PRIMITIVE_TYPE::POLY_LINE);
            //                    break;
            //            }

            break;
        case Qt::ControlModifier:
            switch (event->key()) {
                case Qt::Key_Z:
                    m_actionHandler->undoAction();
                    break;
                case Qt::Key_R:
                    m_actionHandler->redoAction();
                    break;

                default:
                    break;
            }
            break;
    }
}
