//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_PENWIDGET_H
#define GOTIKZ_PENWIDGET_H

#include "ActionWidget.h"
#include "GroupBoxWidget.h"

#include <QPen>

class ColorWidget;

class PenWidget : public ActionWidget, public GroupBoxWidget {

  public:
    explicit PenWidget(QWidget* parent = 0);
    PenWidget(size_t indexOfPrimitive, QWidget* parent = 0);

  private:
    void setColor(QColor color);
    void setWidth(int width);
    void create();

    size_t m_indexOfPrimitive = std::numeric_limits<size_t>::max();
    QPen   m_pen;
};

#endif // GOTIKZ_PENWIDGET_H
