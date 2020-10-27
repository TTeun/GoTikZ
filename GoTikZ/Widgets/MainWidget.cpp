#include "MainWidget.h"

#include "Actions/ChangeMousePointerTypeAction.h"
#include "DrawWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/RightSideBar.h"

#include <QHBoxLayout>

MainWidget::MainWidget(QWidget* parent, Model* model, ActionHandler* actionHandler) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar->groupBox());

    m_drawWidget = new DrawWidget(nullptr, model, actionHandler);
    layout->addWidget(m_drawWidget);

    m_rightSideBar = new RightSideBar(nullptr);
    layout->addWidget(m_rightSideBar->groupBox());

    QObject::connect(m_drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QWidget::*)(void)>(&QWidget::update));
}

MainWidget::~MainWidget() {
}
