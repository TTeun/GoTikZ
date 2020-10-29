//
// Created by pc on 16-10-20.
//

#include "GridState.h"
bool view::GridState::showGrid() const {
    return m_showGrid;
}

size_t view::GridState::gridSpacing() const {
    return m_gridSpacing;
}

void view::GridState::setShowGrid(bool show) {
    m_showGrid = show;
}

void view::GridState::setGridSpacing(size_t spacing) {
    if (spacing == 0) {
        spacing = 1;
    }
    m_gridSpacing = spacing;
}
