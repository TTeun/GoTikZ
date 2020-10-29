//
// Created by pc on 16-10-20.
//

#include "MousePointerTypeSelectWidget.h"

#include "Controller/Actions/ChangeMousePointerTypeAction.h"
#include "Model/MousePointerTypeEnum.h"

#include <QButtonGroup>
#include <QGroupBox>
#include <QLayout>
#include <QRadioButton>

view::MousePointerTypeSelectWidget::MousePointerTypeSelectWidget(QWidget* parent) : GroupBoxContainer(nullptr, "Mode") {
    setLayout(new QHBoxLayout(this));
    m_buttonGroup = new QButtonGroup();

    addTypeButton("Line", true);
    addTypeButton("Circle", false);
    addTypeButton("Point", false);
    addTypeButton("PolyLine", false);
    addTypeButton("Select", false);

    QObject::connect(m_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked),
                     this, &MousePointerTypeSelectWidget::mousePointerTypeButtonClicked);
    layout()->addWidget(m_groupBox);
}

void view::MousePointerTypeSelectWidget::setSelectedButton(MOUSE_POINTER_TYPE type) {
    QString string;
    switch (type) {
        case MOUSE_POINTER_TYPE::LINE:
            string = "Line";
            break;
        case MOUSE_POINTER_TYPE::POINT:
            string = "Point";
            break;
        case MOUSE_POINTER_TYPE::CIRCLE:
            string = "Circle";
            break;
        case MOUSE_POINTER_TYPE::POLY_LINE:
            string = "PolyLine";
            break;
        case MOUSE_POINTER_TYPE::SELECT:
            string = "Select";
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

void view::MousePointerTypeSelectWidget::addTypeButton(const QString& title, bool selected) {
    auto* radioButton = new QRadioButton(m_groupBox);
    radioButton->setChecked(selected);
    radioButton->setText(title);
    m_buttonGroup->addButton(radioButton);
    m_buttonGroup->setId(radioButton, m_buttonGroup->buttons().size() - 1);
    m_groupBox->layout()->addWidget(radioButton);
}

void view::MousePointerTypeSelectWidget::mousePointerTypeButtonClicked(QAbstractButton* button) {
    auto type = mousePointerTypeFromString(button->text());
    switch (type) {
        case MOUSE_POINTER_TYPE::POINT:
            emit actionDone(new controller::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE::POINT));
            break;
        case MOUSE_POINTER_TYPE::LINE:
            emit actionDone(new controller::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE::LINE));
            break;
        case MOUSE_POINTER_TYPE::CIRCLE:
            emit actionDone(new controller::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE::CIRCLE));
            break;
        case MOUSE_POINTER_TYPE::POLY_LINE:
            emit actionDone(new controller::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE::POLY_LINE));
            break;
        case MOUSE_POINTER_TYPE::SELECT:
            emit actionDone(new controller::ChangeMousePointerTypeAction(MOUSE_POINTER_TYPE::SELECT));
            break;
    }
}
