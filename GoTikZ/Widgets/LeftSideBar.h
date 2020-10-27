//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "GroupBoxContainer.h"

class PenWidget;
class PrimitiveSelectWidget;
class GridSettingWidget;

class LeftSideBar : public GroupBoxContainer {

  public:
    explicit LeftSideBar(QWidget* parent);
    PrimitiveSelectWidget* m_primitiveSelectionWidget;
    GridSettingWidget*     m_gridSettingWidget;
    PenWidget*             m_penWidget;

    PrimitiveSelectWidget* primitiveSelectWidget() const;
    GridSettingWidget*     gridSettingWidget() const;
    PenWidget*             penWidget() const;
};

#endif // GOTIKZ_LEFTSIDEBAR_H
