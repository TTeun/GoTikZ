//
// Created by pc on 15-10-20.
//

#include "RightSideBar.h"

#include <QGroupBox>
#include <QLayout>
#include <QtWidgets/QPushButton>

RightSideBar::RightSideBar(QWidget* parent) : GroupBoxContainer(parent, "Right") {
    auto* thisLayout = layout();
    auto* pb = new QPushButton(m_groupBox);
    thisLayout->addWidget(pb);
}
