//
// Created by pc on 16-10-20.
//

#include "PrimitiveSelectWidget.h"

#include "../Actions/ChangePrimitiveAction.h"

#include <QDebug>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

PrimitiveSelectWidget::PrimitiveSelectWidget(QWidget* parent) : ActionWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    auto* groupBox       = new QGroupBox(this);
    auto* groupBoxLayout = new QVBoxLayout(groupBox);
    groupBox->setLayout(groupBoxLayout);
    groupBox->setTitle("Primitive");

    m_buttonGroup = new QButtonGroup(groupBox);

    addTypeButton(groupBox, "Line", true);
    addTypeButton(groupBox, "Circle", false);
    addTypeButton(groupBox, "Point", false);
    addTypeButton(groupBox, "PolyLine", false);

    connect(m_buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(primitiveSelected(QAbstractButton*)));

    groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    layout->addWidget(groupBox);
    setLayout(layout);
}

void PrimitiveSelectWidget::setSelectedButton(DrawWidget::PRIMITIVE_TYPE type) {
    QString string;
    switch (type) {
        case DrawWidget::PRIMITIVE_TYPE::LINE:
            string = "Line";
            break;
        case DrawWidget::PRIMITIVE_TYPE::POINT:
            string = "Point";
            break;
        case DrawWidget::PRIMITIVE_TYPE::CIRCLE:
            string = "Circle";
            break;
        case DrawWidget::PRIMITIVE_TYPE::POLY_LINE:
            string = "PolyLine";
            break;
    }

    const size_t numberOfButtons = m_buttonGroup->buttons().size();
    for (size_t i = 0; i != numberOfButtons; ++i) {
        if (m_buttonGroup->button(i)->text() == string) {
            m_buttonGroup->button(i)->setChecked(true);
            emit m_buttonGroup->buttonClicked(m_buttonGroup->button(i));
            return;
        }
    }
    assert(false);
}

void PrimitiveSelectWidget::addTypeButton(QGroupBox* groupbox, const QString& title, bool selected) {
    auto* radioButton = new QRadioButton(groupbox);
    radioButton->setChecked(selected);
    radioButton->setText(title);
    m_buttonGroup->addButton(radioButton);
    m_buttonGroup->setId(radioButton, m_buttonGroup->buttons().size() - 1);
    groupbox->layout()->addWidget(radioButton);
}
void PrimitiveSelectWidget::primitiveSelected(QAbstractButton* button) {
    if (button->text() == QString("Point")) {
        emit actionDone(new ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE::POINT), false, false);
    } else if (button->text() == QString("Line")) {
        emit actionDone(new ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE::LINE), false, false);
    } else if (button->text() == QString("Circle")) {
        emit actionDone(new ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE::CIRCLE), false, false);
    } else if (button->text() == QString("PolyLine")) {
        emit actionDone(new ChangePrimitiveAction(DrawWidget::PRIMITIVE_TYPE::POLY_LINE), false, false);
    } else {
    }
}
