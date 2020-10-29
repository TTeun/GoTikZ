#include "MainWidget.h"

#include "DrawWidget.h"
#include "LeftSideBar.h"
#include "Model/Model.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"
#include "RightSideBar.h"

#include <QGroupBox>
#include <QHBoxLayout>

view::MainWidget::MainWidget(QWidget* parent, const model::Model* model, controller::Controller* actionHandler)
    : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar);

    m_drawWidget = new view::DrawWidget(nullptr, model, actionHandler);
    layout->addWidget(m_drawWidget);

    m_rightSideBar = new view::RightSideBar(nullptr);
    layout->addWidget(m_rightSideBar);
}

view::DrawWidget* view::MainWidget::drawWidget() {
    return m_drawWidget;
}

view::LeftSideBar* view::MainWidget::leftSideBar() {
    return m_leftSideBar;
}

view::RightSideBar* view::MainWidget::rightSideBar() {
    return m_rightSideBar;
}

const view::DrawWidget* view::MainWidget::drawWidget() const {
    return m_drawWidget;
}

const view::LeftSideBar* view::MainWidget::leftSideBar() const {
    return m_leftSideBar;
}

const view::RightSideBar* view::MainWidget::rightSideBar() const {
    return m_rightSideBar;
}
