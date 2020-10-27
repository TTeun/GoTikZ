#include "MainWidget.h"

#include "Actions/ChangePrimitiveAction.h"
#include "Widgets/ColorWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/PrimitiveSelectWidget.h"

#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>

MainWidget::MainWidget(QWidget* parent, Model* model, ActionHandler* actionHandler) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar->groupBox());

    m_drawWidget = new DrawWidget(nullptr, model, actionHandler);
    layout->addWidget(m_drawWidget);

    QObject::connect(m_drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QWidget::*)(void)>(&QWidget::update));
}

MainWidget::~MainWidget() {
}
