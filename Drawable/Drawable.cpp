//
// Created by pc on 15-10-20.
//

#include "Drawable.h"

#include "View/ColorPresets.h"

#include <QPainter>

size_t Drawable::s_maxIndex = 0;

Drawable::Drawable(QPen pen) : m_pen(std::move(pen)) {
    m_pen.setCapStyle(Qt::RoundCap);
    m_index = s_maxIndex;
    ++s_maxIndex;
}

void Drawable::draw(QPainter* painter, DRAW_FLAGS drawFlag,
                    const controller::CoordinateConverter& coordinateConverter) const {
    painter->setRenderHint(QPainter::Antialiasing, true);
    switch (drawFlag) {
        case DRAW_FLAGS::NONE:
            painter->setPen(m_pen);
            break;
        case DRAW_FLAGS::SELECTED: {
            auto selectedPen = QPen(ColorPresets::s_selectedColor, m_pen.width() + 2);
            selectedPen.setCapStyle(Qt::RoundCap);
            painter->setPen(selectedPen);
        } break;
        case DRAW_FLAGS::HIGHLIGHTED: {
            auto highlightedPen = QPen(m_pen.color(), m_pen.width() + 1);
            highlightedPen.setCapStyle(Qt::RoundCap);
            painter->setPen(highlightedPen);
        } break;
    }
}

size_t Drawable::index() const {
    return m_index;
}

void Drawable::setPen(const QPen& pen) {
    m_pen = pen;
}

const QPen& Drawable::pen() const {
    return m_pen;
}

void Drawable::setVisible(bool visible) {
    m_isVisible = visible;
}

bool Drawable::visible() const {
    return m_isVisible;
}
