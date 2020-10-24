//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "GroupBoxWidget.h"

#include <QWidget>

class RightSideBar : public QWidget, public GroupBoxWidget {

  public:
    explicit RightSideBar(QWidget* parent = 0);
};

#endif // GOTIKZ_LEFTSIDEBAR_H
