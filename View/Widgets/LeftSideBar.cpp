//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"

#include <QLayout>
#include <QToolBox>

View::LeftSideBar::LeftSideBar(QWidget* parent) : QWidget(parent), GroupBoxContainer(parent, "Settings") {
    setLayout(new QVBoxLayout(this));
    layout()->addWidget(m_groupBox);
    layout()->setSpacing(0);
    layout()->setMargin(0);
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    setSizePolicy(sizePolicy);

    auto* contentsLayout           = m_groupBox->layout();
    m_mousePointerTypeSelectWidget = new View::MousePointerTypeSelectWidget(m_groupBox);
    m_gridSettingWidget            = new View::GridSettingWidget(m_groupBox);
    m_penWidget                    = new View::PenWidget(m_groupBox);
    contentsLayout->addWidget(m_mousePointerTypeSelectWidget);
    contentsLayout->addWidget(m_gridSettingWidget);
    contentsLayout->addWidget(m_penWidget);
}

View::MousePointerTypeSelectWidget* View::LeftSideBar::mousePointerTypeSelect() const {
    return m_mousePointerTypeSelectWidget;
}

View::GridSettingWidget* View::LeftSideBar::gridSettingWidget() const {
    return m_gridSettingWidget;
}

View::PenWidget* View::LeftSideBar::penWidget() const {
    return m_penWidget;
}
