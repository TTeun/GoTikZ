//
// Created by pc on 31-10-20.
//

#include "Controller/Actions/TranslateControlPointAction.h"

#include "Controller/Controller.h"
#include "Drawable/DrawableHandler.h"
#include "Model/Model.h"

controller::TranslateControlPointAction::TranslateControlPointAction(size_t index, const QPointF& translation)
    : m_index(index), m_translation(translation) {
}

void controller::TranslateControlPointAction::doAction(controller::Controller* controller) {
    auto& controlPoints = controller->model()->drawableHandler().controlPoints();
    auto  it            = std::find_if(
        controlPoints.begin(), controlPoints.end(),
        [&](const std::unique_ptr<ControlPoint>& controlPoint) { return m_index == controlPoint->index(); });
    assert(it != controlPoints.end());
    (*it)->translate(m_translation);
    controller->draw();
}

void controller::TranslateControlPointAction::undoAction(controller::Controller* controller) {
    auto& controlPoints = controller->model()->drawableHandler().controlPoints();
    auto  it            = std::find_if(
        controlPoints.begin(), controlPoints.end(),
        [&](const std::unique_ptr<ControlPoint>& controlPoint) { return m_index == controlPoint->index(); });
    assert(it != controlPoints.end());
    (*it)->translate(-m_translation);
    controller->draw();
}
