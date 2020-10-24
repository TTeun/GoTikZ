//
// Created by pc on 15-10-20.
//

#include "RightSideBar.h"

#include <QGroupBox>
#include <QLayout>
#include <QtWidgets/QPushButton>

RightSideBar::RightSideBar(QWidget* parent) : QWidget(parent) {
    auto* layout = GroupBoxWidget::init(this, "Settings")->layout();

    auto* pb = new QPushButton(this);
    layout->addWidget(pb);
}
