//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_DRAWABLEEDITWIDGET_H
#define GOTIKZ_DRAWABLEEDITWIDGET_H

#include <QWidget>

namespace view {
    class DrawableEditWidget : public QWidget {
        Q_OBJECT

      public:
        DrawableEditWidget(QWidget* parent) : QWidget(parent) {
        }

      public slots:
        virtual void needsUpdate() = 0;
    };
} // namespace view

#endif // GOTIKZ_DRAWABLEEDITWIDGET_H
