//
// Created by pc on 15-10-20.
//

#include "LeftSideBar.h"

#include <QVBoxLayout>

LeftSideBar::LeftSideBar(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    m_primitiveSelectionWidget = new PrimitiveSelectWidget(this);
    m_gridSettingWidget        = new GridSettingWidget(this);
    m_penWidget                = new PenWidget(this);
    layout->addWidget(m_primitiveSelectionWidget);
    layout->addWidget(m_gridSettingWidget);
    layout->addWidget(m_penWidget);
    setLayout(layout);
}

//}
