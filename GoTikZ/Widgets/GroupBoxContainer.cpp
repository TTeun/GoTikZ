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
    layout->setMargin(2);
    m_groupBox->setLayout(layout);

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_groupBox->setSizePolicy(sizePolicy);
}

QGroupBox* GroupBoxContainer::groupBox() {
    return m_groupBox;
}

QLayout* GroupBoxContainer::layout() {
    return m_groupBox->layout();
}
