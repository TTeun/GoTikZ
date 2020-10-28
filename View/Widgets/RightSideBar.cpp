//
// Created by pc on 15-10-20.
//

#include "RightSideBar.h"

#include "AuxWidgets/XyWidget.h"

#include <QGroupBox>
#include <QLayout>
#include <QtWidgets/QPushButton>

View::RightSideBar::RightSideBar(QWidget* parent) : QWidget(parent), GroupBoxContainer(parent, "Edit") {
    setLayout(new QVBoxLayout(this));
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    setSizePolicy(sizePolicy);
    layout()->addWidget(m_groupBox);
}

void View::RightSideBar::addWidget(QWidget* widget) {
    assert(m_groupBox->layout()->children().empty());
    widget->setParent(m_groupBox);
    m_groupBox->layout()->addWidget(widget);
    repaint();
}

void View::RightSideBar::clearWidget() {
    QLayoutItem* item;
    while ((item = m_groupBox->layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}
