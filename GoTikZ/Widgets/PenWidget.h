//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_PENWIDGET_H
#define GOTIKZ_PENWIDGET_H

#include "ActionWidget.h"
#include "GroupBoxContainer.h"

#include <QPen>

class ColorWidget;

class PenWidget : public ActionWidget, public GroupBoxContainer {

    Q_OBJECT

  public:
    explicit PenWidget(QWidget* parent);
    PenWidget(size_t indexOfPrimitive, QWidget* parent = 0);

 private slots:
    void setColor(QColor color);

  private:
    void setWidth(int width);
    void create();

    size_t m_indexOfPrimitive = std::numeric_limits<size_t>::max();
    QPen   m_pen;
};

#endif // GOTIKZ_PENWIDGET_H
