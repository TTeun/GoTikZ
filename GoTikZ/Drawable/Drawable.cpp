//
// Created by pc on 15-10-20.
//

#include "Drawable.h"

#include "../Widgets/GroupBoxContainer.h"

#include <QPainter>
#include <utility>

size_t Drawable::s_maxIndex = 0;

Drawable::Drawable(QPen pen) : m_pen(std::move(pen)) {
    m_index = s_maxIndex;
    ++s_maxIndex;
}

void Drawable::draw(QPainter* painter, DRAW_FLAGS drawFlag) const {
    switch (drawFlag) {
        case DRAW_FLAGS::NONE:
            painter->setPen(m_pen);
            break;
        case DRAW_FLAGS::SELECTED:
            painter->setPen(QPen(Qt::green, m_pen.width()));
            break;
        case DRAW_FLAGS::HIGHLIGHTED:
            painter->setPen(QPen(m_pen.color(), m_pen.width() + 2));
            break;
    }
}

size_t Drawable::index() const {
    return m_index;
}

GroupBoxContainer* Drawable::toWidget(ActionHandler* actionHandler) {
    return new GroupBoxContainer(nullptr, "stubb");
}

void Drawable::setPen(const QPen& pen) {
    m_pen = pen;
}

const QPen& Drawable::pen() const {
    return m_pen;
}
