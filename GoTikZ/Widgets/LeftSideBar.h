//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "GroupBoxWidget.h"

#include <QWidget>

class PenWidget;
class PrimitiveSelectWidget;
class GridSettingWidget;

class LeftSideBar : public QWidget, public GroupBoxWidget {
    Q_OBJECT

  public:
    explicit LeftSideBar(QWidget* parent = 0);
    PrimitiveSelectWidget* m_primitiveSelectionWidget;
    GridSettingWidget*     m_gridSettingWidget;
    PenWidget*             m_penWidget;

    PrimitiveSelectWidget* primitiveSelectWidget() const;
    GridSettingWidget*     gridSettingWidget() const;
    PenWidget*             penWidget() const;
};

#endif // GOTIKZ_LEFTSIDEBAR_H
