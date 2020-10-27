//
// Created by pc on 16-10-20.
//

#include "PrimitiveSelectWidget.h"

#include "../Actions/ChangePrimitiveAction.h"

#include <QButtonGroup>
#include <QGroupBox>
#include <QLayout>
#include <QRadioButton>

PrimitiveSelectWidget::PrimitiveSelectWidget(QWidget* parent) {
    m_groupBox = new QGroupBox();
    m_groupBox->setTitle("Primitive");
    auto* layout = new QVBoxLayout(parent);
    layout->setSpacing(0);
    layout->setMargin(2);
    m_groupBox->setLayout(layout);
    m_groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 238)"));

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    m_groupBox->setSizePolicy(sizePolicy);

    m_groupBox->setAlignment(Qt::AlignTop);
    m_groupBox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    m_buttonGroup = new QButtonGroup(m_groupBox);

    addTypeButton("Line", true);
    addTypeButton("Circle", false);
    addTypeButton("Point", false);
    addTypeButton("PolyLine", false);

    QObject::connect(m_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked),
                     this, &PrimitiveSelectWidget::primitiveSelected);
}

void PrimitiveSelectWidget::setSelectedButton(Drawable::PRIMITIVE_TYPE type) {
    QString string;
    switch (type) {
        case Drawable::PRIMITIVE_TYPE::LINE:
            string = "Line";
            break;
        case Drawable::PRIMITIVE_TYPE::POINT:
            string = "Point";
            break;
        case Drawable::PRIMITIVE_TYPE::CIRCLE:
            string = "Circle";
            break;
        case Drawable::PRIMITIVE_TYPE::POLY_LINE:
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

void PrimitiveSelectWidget::addTypeButton(const QString& title, bool selected) {
    auto* radioButton = new QRadioButton(m_groupBox);
    radioButton->setChecked(selected);
    radioButton->setText(title);
    m_buttonGroup->addButton(radioButton);
    m_buttonGroup->setId(radioButton, m_buttonGroup->buttons().size() - 1);
    m_groupBox->layout()->addWidget(radioButton);
}

void PrimitiveSelectWidget::primitiveSelected(QAbstractButton* button) {
    //    m_buttonGroup->blockSignals(false);
    if (button->text() == QString("Point")) {
        emit actionDone(new ChangePrimitiveAction(Drawable::PRIMITIVE_TYPE::POINT));
    } else if (button->text() == QString("Line")) {
        emit actionDone(new ChangePrimitiveAction(Drawable::PRIMITIVE_TYPE::LINE));
    } else if (button->text() == QString("Circle")) {
        emit actionDone(new ChangePrimitiveAction(Drawable::PRIMITIVE_TYPE::CIRCLE));
    } else if (button->text() == QString("PolyLine")) {
        emit actionDone(new ChangePrimitiveAction(Drawable::PRIMITIVE_TYPE::POLY_LINE));
    } else {
    }
}
