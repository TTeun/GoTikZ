//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "MousePointerTypeSelectWidget.h"
#include "PenWidget.h"

#include <QLayout>
#include <QToolBox>

LeftSideBar::LeftSideBar(QWidget* parent) : QWidget(parent), GroupBoxContainer(parent, "Settings") {
    setLayout(new QVBoxLayout(this));

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    setSizePolicy(sizePolicy);

    auto* contentsLayout           = m_groupBox->layout();
    m_mousePointerTypeSelectWidget = new MousePointerTypeSelectWidget(m_groupBox);
    m_gridSettingWidget            = new GridSettingWidget(m_groupBox);
    m_penWidget                    = new PenWidget(m_groupBox);
    contentsLayout->addWidget(m_mousePointerTypeSelectWidget);
    contentsLayout->addWidget(m_gridSettingWidget);
    contentsLayout->addWidget(m_penWidget);
    layout()->addWidget(m_groupBox);
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
