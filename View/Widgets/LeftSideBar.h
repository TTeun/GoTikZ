//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

namespace view {
    class PenWidget;
    class PrimitiveTypeSelectWidget;
    class GridSettingWidget;

    class LeftSideBar : public QWidget, public GroupBoxContainer {

      public:
        explicit LeftSideBar(QWidget* parent);
        PrimitiveTypeSelectWidget* m_mousePointerTypeSelectWidget;
        GridSettingWidget*            m_gridSettingWidget;
        PenWidget*                    m_penWidget;

        PrimitiveTypeSelectWidget* mousePointerTypeSelect() const;
        GridSettingWidget*            gridSettingWidget() const;
        PenWidget*                    penWidget() const;
    };
} // namespace view

#endif // GOTIKZ_LEFTSIDEBAR_H
