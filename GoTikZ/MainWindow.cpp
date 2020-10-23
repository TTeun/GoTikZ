#include "MainWindow.h"

#include "Actions/ChangePrimitiveAction.h"
#include "Widgets/ColorWidget.h"
#include "Widgets/LeftSideBar.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QRadioButton>
#include <QSpinBox>
#include <memory>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    auto* leftSideBar = ui->leftSideBarContent;
    auto* drawWidget  = ui->widget;
    m_actionHandler   = std::make_unique<ActionHandler>(drawWidget, leftSideBar->m_primitiveSelectionWidget);

    QObject::connect(drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QMainWindow::*)(void)>(&QMainWindow::update));
    QObject::connect(leftSideBar->m_colorWidget, &ColorWidget::colorUpdated, drawWidget, &DrawWidget::colorChanged);
//    QObject::connect(leftSideBar->m_gridButton, &QRadioButton::clicked, drawWidget, &DrawWidget::showGrid);
//    QObject::connect(leftSideBar->m_gridSpacingSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
//                     drawWidget, &DrawWidget::setGridSpacing);

    setCentralWidget(drawWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->modifiers()) {
        case Qt::NoModifier:
            switch (event->key()) {
                case Qt::Key_P:
                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::POINT);
                    break;
                case Qt::Key_L:
                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::LINE);
                    break;
                case Qt::Key_C:
                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::CIRCLE);
                    break;
                case Qt::Key_Y:
                    ui->leftSideBarContent->m_primitiveSelectionWidget->setSelectedButton(
                        DrawWidget::PRIMITIVE_TYPE::POLY_LINE);
                    break;
            }

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
