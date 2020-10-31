//
// Created by pc on 16-10-20.
//

#include "ShowPrimitiveAction.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Widgets/DrawWidget.h"

#include <QDebug>

controller::ShowPrimitiveAction::ShowPrimitiveAction(size_t indexOfPrimitive) : m_indexOfPrimitive(indexOfPrimitive) {
}

void controller::ShowPrimitiveAction::doAction(controller::Controller* controller) {
    controller->model()->drawableHandler().showDrawable(m_indexOfPrimitive);

    controller->updateControlPoints();
    controller->model()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}

void controller::ShowPrimitiveAction::undoAction(controller::Controller* controller) {
    controller->model()->drawableHandler().hideDrawable(m_indexOfPrimitive);
    controller->setSelectedControlPoint(nullptr);
    controller->updateControlPoints();
    controller->model()->drawableHandler().clearSelectedAndHighlighted();
    controller->draw();
}
