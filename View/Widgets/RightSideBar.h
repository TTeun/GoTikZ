//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_RIGHTSIDEBAR_H
#define GOTIKZ_RIGHTSIDEBAR_H

#include "AuxWidgets/GroupBoxContainer.h"

#include <QWidget>

namespace View {
    class RightSideBar : public QWidget, public GroupBoxContainer {

      public:
        explicit RightSideBar(QWidget* parent);

        void addWidget(QWidget* widget);

        void clearWidget();
    };
} // namespace View

#endif // GOTIKZ_RIGHTSIDEBAR_H
