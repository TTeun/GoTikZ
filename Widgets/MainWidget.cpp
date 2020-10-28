#include "MainWidget.h"

#include "DrawWidget.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/RightSideBar.h"

#include <QGroupBox>
#include <QHBoxLayout>

MainWidget::MainWidget(QWidget* parent, Model* model, ActionHandler* actionHandler) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar);

    m_drawWidget = new DrawWidget(nullptr, model, actionHandler);
    layout->addWidget(m_drawWidget);

    m_rightSideBar = new RightSideBar(nullptr);
    layout->addWidget(m_rightSideBar);
}

MainWidget::~MainWidget() = default;
