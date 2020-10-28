//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"

#include <QLayout>
#include <QToolBox>

LeftSideBar::LeftSideBar(QWidget* parent) : GroupBoxContainer(parent, "Settings") {
    auto* contentsLayout = layout();

    m_mousePointerTypeSelectWidget = new MousePointerTypeSelectWidget(groupBox());
    m_gridSettingWidget            = new GridSettingWidget(groupBox());
    m_penWidget                    = new PenWidget(groupBox());
    contentsLayout->addWidget(m_mousePointerTypeSelectWidget->groupBox());
    contentsLayout->addWidget(m_gridSettingWidget->groupBox());
    contentsLayout->addWidget(m_penWidget->groupBox());
}

MousePointerTypeSelectWidget* LeftSideBar::mousePointerTypeSelect() const {
    return m_mousePointerTypeSelectWidget;
}

GridSettingWidget* LeftSideBar::gridSettingWidget() const {
    return m_gridSettingWidget;
}

PenWidget* LeftSideBar::penWidget() const {
    return m_penWidget;
}
