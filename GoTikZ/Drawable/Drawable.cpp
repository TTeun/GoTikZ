//
// Created by pc on 15-10-20.
//

#include "Drawable.h"

#include <QPainter>
#include <utility>

size_t Drawable::s_maxIndex = 0;

Drawable::Drawable(QPen pen) : m_pen(std::move(pen)) {
    m_index = s_maxIndex;
    ++s_maxIndex;
}

void Drawable::draw(QPainter* painter) const{
    painter->setPen(m_pen);
}

size_t Drawable::index() const {
    return m_index;
}
