//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include "GridSettingWidget.h"
#include "PenWidget.h"
#include "PrimitiveSelectWidget.h"

#include <QLayout>

LeftSideBar::LeftSideBar(QWidget* parent) : QWidget(parent) {
    auto* layout = GroupBoxWidget::init(this, "Settings")->layout();

    m_primitiveSelectionWidget = new PrimitiveSelectWidget(this);
    m_gridSettingWidget        = new GridSettingWidget(this);
    m_penWidget                = new PenWidget(this);
    layout->addWidget(m_primitiveSelectionWidget);
    layout->addWidget(m_gridSettingWidget);
    layout->addWidget(m_penWidget);
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

//}
