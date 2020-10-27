//
// Created by pc on 24-10-20.
//

#include "GroupBoxContainer.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>

GroupBoxContainer::GroupBoxContainer(QWidget* parent, QString title) : m_groupBox(new QGroupBox(parent)) {
    m_groupBox->setTitle(title);
    auto* layout = new QVBoxLayout(parent);
    layout->setSpacing(0);
    layout->setMargin(0);
    m_groupBox->setLayout(layout);
    m_groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 238)"));

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_groupBox->setSizePolicy(sizePolicy);
}

QGroupBox* GroupBoxContainer::groupBox() {
    return m_groupBox;
}

QLayout* GroupBoxContainer::layout() {
    return m_groupBox->layout();
}