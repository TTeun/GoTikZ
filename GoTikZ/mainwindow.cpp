#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Widgets/LeftSideBar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      m_drawWidget(new DrawWidget()) {
  ui->setupUi(this);

  ui->widget = m_drawWidget;

  connect(m_drawWidget, SIGNAL(updateSignal()), this, SLOT(update()));

  connect(ui->leftSideBarContent->m_colorWidget, &ColorWidget::colorUpdated,
          m_drawWidget, &DrawWidget::colorChanged);

  QObject::connect(ui->leftSideBarContent, &LeftSideBar::typeChanged,
                   m_drawWidget, &DrawWidget::typeChanged);

  setCentralWidget(m_drawWidget);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::hoi(QString str) { qDebug() << str << "ASDSADSA"; }
