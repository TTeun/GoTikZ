#include "MainWidget.h"

#include "Actions/ChangePrimitiveAction.h"
#include "Widgets/ColorWidget.h"
#include "Widgets/LeftSideBar.h"
#include "Widgets/PrimitiveSelectWidget.h"

#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>

MainWidget::MainWidget(QWidget* parent) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);

    m_leftSideBar = new LeftSideBar(nullptr);
    layout->addWidget(m_leftSideBar->groupBox());

    auto* drawWidget = new DrawWidget(nullptr);
    layout->addWidget(drawWidget);

    QObject::connect(drawWidget, &DrawWidget::updateSignal, this,
                     static_cast<void (QWidget::*)(void)>(&QWidget::update));

    m_actionHandler = std::make_unique<ActionHandler>(drawWidget, m_leftSideBar);
    m_actionHandler->init();

    resize(800, 600);
}

MainWidget::~MainWidget() {
}

void MainWidget::keyPressEvent(QKeyEvent* event) {
    switch (event->modifiers()) {
        case Qt::NoModifier:
            switch (event->key()) {
                case Qt::Key_P:
                    m_leftSideBar->m_primitiveSelectionWidget->setSelectedButton(DrawWidget::PRIMITIVE_TYPE::POINT);
                    break;
                case Qt::Key_L:
                    m_leftSideBar->m_primitiveSelectionWidget->setSelectedButton(DrawWidget::PRIMITIVE_TYPE::LINE);
                    break;
                case Qt::Key_C:
                    m_leftSideBar->m_primitiveSelectionWidget->setSelectedButton(DrawWidget::PRIMITIVE_TYPE::CIRCLE);
                    break;
                case Qt::Key_Y:
                    m_leftSideBar->m_primitiveSelectionWidget->setSelectedButton(DrawWidget::PRIMITIVE_TYPE::POLY_LINE);
                    break;
            }

            break;
        case Qt::ControlModifier:
            switch (event->key()) {
                case Qt::Key_Z:
                    m_actionHandler->undoAction();
                    break;
                case Qt::Key_R:
                    m_actionHandler->redoAction();
                    break;

                default:
                    break;
            }
            break;
    }
}
