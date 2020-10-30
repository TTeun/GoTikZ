//
// Created by pc on 16-10-20.
//

#include "PrimitiveTypeSelectWidget.h"

#include "Controller/Actions/ChangePrimitiveTypeAction.h"
#include "Model/PrimitiveTypeEnum.h"

#include <QButtonGroup>
#include <QGroupBox>
#include <QLayout>
#include <QRadioButton>

view::PrimitiveTypeSelectWidget::PrimitiveTypeSelectWidget(QWidget* parent) : GroupBoxContainer(nullptr, "Mode") {
    setLayout(new QHBoxLayout(this));
    m_buttonGroup = new QButtonGroup();

    addTypeButton("Line", true);
    addTypeButton("Circle", false);
    addTypeButton("Point", false);
    addTypeButton("PolyLine", false);

    QObject::connect(m_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked),
                     this, &PrimitiveTypeSelectWidget::mousePointerTypeButtonClicked);
    layout()->addWidget(m_groupBox);
}

void view::PrimitiveTypeSelectWidget::setSelectedButton(PRIMITIVE_TYPE type) {
    QString string;
    switch (type) {
        case PRIMITIVE_TYPE::LINE:
            string = "Line";
            break;
        case PRIMITIVE_TYPE::POINT:
            string = "Point";
            break;
        case PRIMITIVE_TYPE::CIRCLE:
            string = "Circle";
            break;
        case PRIMITIVE_TYPE::POLY_LINE:
            string = "PolyLine";
            break;
        case PRIMITIVE_TYPE::STREAM:
            break;
    }

    const size_t numberOfButtons = static_cast<const size_t>(m_buttonGroup->buttons().size());
    for (size_t i = 0; i != numberOfButtons; ++i) {
        if (m_buttonGroup->button(i)->text() == string) {
            m_buttonGroup->button(i)->setChecked(true);
            emit m_buttonGroup->buttonClicked(m_buttonGroup->button(i));
            return;
        }
    }
    assert(false);
}

void view::PrimitiveTypeSelectWidget::addTypeButton(const QString& title, bool selected) {
    auto* radioButton = new QRadioButton(m_groupBox);
    radioButton->setChecked(selected);
    radioButton->setText(title);
    m_buttonGroup->addButton(radioButton);
    m_buttonGroup->setId(radioButton, m_buttonGroup->buttons().size() - 1);
    m_groupBox->layout()->addWidget(radioButton);
}

void view::PrimitiveTypeSelectWidget::mousePointerTypeButtonClicked(QAbstractButton* button) {
    auto type = primitiveTypeFromString(button->text());
    switch (type) {
        case PRIMITIVE_TYPE::POINT:
            emit actionDone(new controller::ChangePrimitiveTypeAction(PRIMITIVE_TYPE::POINT));
            break;
        case PRIMITIVE_TYPE::LINE:
            emit actionDone(new controller::ChangePrimitiveTypeAction(PRIMITIVE_TYPE::LINE));
            break;
        case PRIMITIVE_TYPE::CIRCLE:
            emit actionDone(new controller::ChangePrimitiveTypeAction(PRIMITIVE_TYPE::CIRCLE));
            break;
        case PRIMITIVE_TYPE::POLY_LINE:
            emit actionDone(new controller::ChangePrimitiveTypeAction(PRIMITIVE_TYPE::POLY_LINE));
            break;
        case PRIMITIVE_TYPE::STREAM:
            break;
    }
}
