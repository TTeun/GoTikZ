#include "MainWindow.h"

#include "Widgets/ColorWidget.h"
#include "Widgets/LeftSideBar.h"
#include "ui_mainwindow.h"

#include <QRadioButton>
#include <QSpinBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto* leftSideBar = ui->leftSideBarContent;
    auto* drawWidget = ui->widget;

    QObject::connect(drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QMainWindow::*)(void)>(&QMainWindow::update));
    QObject::connect(leftSideBar->m_colorWidget, &ColorWidget::colorUpdated, drawWidget, &DrawWidget::colorChanged);
    QObject::connect(leftSideBar, &LeftSideBar::typeChanged, drawWidget, &DrawWidget::typeChanged);
    QObject::connect(leftSideBar->m_gridButton, &QRadioButton::clicked, drawWidget, &DrawWidget::showGrid);
    QObject::connect(leftSideBar->m_gridSpacingSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                     drawWidget, &DrawWidget::setGridSpacing);

    setCentralWidget(drawWidget);
}

MainWindow::~MainWindow() { delete ui; }
