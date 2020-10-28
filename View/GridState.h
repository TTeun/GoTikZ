//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_GRIDSTATE_H
#define GOTIKZ_GRIDSTATE_H

#include <cstddef>

namespace View {
    class GridState {
      public:
        bool   showGrid() const;
        size_t gridSpacing() const;
        void   setShowGrid(bool show);
        void   setGridSpacing(size_t spacing);

      private:
        bool   m_showGrid    = true;
        size_t m_gridSpacing = 50;
    };
} // namespace View

#endif // GOTIKZ_GRIDSTATE_H
