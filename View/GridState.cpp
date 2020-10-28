//
// Created by pc on 16-10-20.
//

#include "GridState.h"
bool View::GridState::showGrid() const {
    return m_showGrid;
}

size_t View::GridState::gridSpacing() const {
    return m_gridSpacing;
}

void View::GridState::setShowGrid(bool show) {
    m_showGrid = show;
}

void View::GridState::setGridSpacing(size_t spacing) {
    if (spacing == 0) {
        spacing = 1;
    }
    m_gridSpacing = spacing;
}
