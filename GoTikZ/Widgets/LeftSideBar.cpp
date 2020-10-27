//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"

#include <QLayout>

LeftSideBar::LeftSideBar(QWidget* parent) : GroupBoxContainer(parent, "Settings") {
    auto* contentsLayout = layout();

    m_mousePointerTypeSelectWidget = new MousePointerTypeSelectWidget(nullptr);
    m_gridSettingWidget            = new GridSettingWidget(nullptr);
    m_penWidget                    = new PenWidget(nullptr);
    contentsLayout->addWidget(m_mousePointerTypeSelectWidget->groupBox());
    contentsLayout->addWidget(m_gridSettingWidget->groupBox());
    contentsLayout->addWidget(m_penWidget->groupBox());

    contentsLayout->setAlignment(Qt::AlignTop);
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
