#include "MainWidget.h"

#include "DrawWidget.h"
#include "LeftSideBar.h"
#include "Model/ModelHandler.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"
#include "RightSideBar.h"

#include <QGroupBox>
#include <QHBoxLayout>

View::MainWidget::MainWidget(QWidget* parent, const Model::ModelHandler* model,
                             Controller::ActionHandler* actionHandler)
    : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar);

    m_drawWidget = new View::DrawWidget(nullptr, model, actionHandler);
    layout->addWidget(m_drawWidget);

    m_rightSideBar = new View::RightSideBar(nullptr);
    layout->addWidget(m_rightSideBar);
}

View::DrawWidget* View::MainWidget::drawWidget() {
    return m_drawWidget;
}

View::LeftSideBar* View::MainWidget::leftSideBar() {
    return m_leftSideBar;
}

View::RightSideBar* View::MainWidget::rightSideBar() {
    return m_rightSideBar;
}

const View::DrawWidget* View::MainWidget::drawWidget() const {
    return m_drawWidget;
}

const View::LeftSideBar* View::MainWidget::leftSideBar() const {
    return m_leftSideBar;
}

const View::RightSideBar* View::MainWidget::rightSideBar() const {
    return m_rightSideBar;
}
