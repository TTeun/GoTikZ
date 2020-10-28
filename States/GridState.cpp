//
// Created by pc on 16-10-20.
//

#include "GridState.h"
bool GridState::showGrid() const {
    return m_showGrid;
}

size_t GridState::gridSpacing() const {
    return m_gridSpacing;
}

void GridState::setShowGrid(bool show) {
    m_showGrid = show;
}

void GridState::setGridSpacing(size_t spacing) {
    if (spacing == 0) {
        spacing = 1;
    }
    m_gridSpacing = spacing;
}
