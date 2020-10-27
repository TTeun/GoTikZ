//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "PenWidget.h"
#include "PrimitiveSelectWidget.h"

#include <QLayout>

LeftSideBar::LeftSideBar(QWidget* parent) : GroupBoxContainer(parent, "Settings") {
    auto* contentsLayout = layout();

    m_primitiveSelectionWidget = new PrimitiveSelectWidget(nullptr);
    m_gridSettingWidget        = new GridSettingWidget(nullptr);
    m_penWidget                = new PenWidget(nullptr);
    contentsLayout->addWidget(m_primitiveSelectionWidget->m_groupBox);
    contentsLayout->addWidget(m_gridSettingWidget->groupBox());
    contentsLayout->addWidget(m_penWidget->groupBox());

    m_groupBox->resize(80,400);
}

PrimitiveSelectWidget* LeftSideBar::primitiveSelectWidget() const {
    return m_primitiveSelectionWidget;
}

GridSettingWidget* LeftSideBar::gridSettingWidget() const {
    return m_gridSettingWidget;
}

PenWidget* LeftSideBar::penWidget() const {
    return m_penWidget;
}

