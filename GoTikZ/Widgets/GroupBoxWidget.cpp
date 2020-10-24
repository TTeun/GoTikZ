//
// Created by pc on 24-10-20.
//

#include "GroupBoxWidget.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>

QGroupBox* GroupBoxWidget::init(QWidget* parent, const QString& title) {
    auto* layout         = new QVBoxLayout(parent);
    auto* groupBox       = new QGroupBox(parent);
    auto* groupBoxLayout = new QVBoxLayout(groupBox);
    groupBoxLayout->setSpacing(0);
    groupBoxLayout->setMargin(0);

    groupBox->setLayout(groupBoxLayout);
    groupBox->setTitle(title);
    groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 238)"));

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
    groupBox->setSizePolicy(sizePolicy);

    layout->addWidget(groupBox, 0, Qt::AlignTop);
    parent->setLayout(layout);
    return groupBox;
}
