//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

class PenWidget;
class MousePointerTypeSelectWidget;
class GridSettingWidget;

class LeftSideBar : public QWidget, public GroupBoxContainer {

  public:
    explicit LeftSideBar(QWidget* parent);
    MousePointerTypeSelectWidget* m_mousePointerTypeSelectWidget;
    GridSettingWidget*            m_gridSettingWidget;
    PenWidget*                    m_penWidget;

    MousePointerTypeSelectWidget* mousePointerTypeSelect() const;
    GridSettingWidget*            gridSettingWidget() const;
    PenWidget*                    penWidget() const;
};

#endif // GOTIKZ_LEFTSIDEBAR_H
