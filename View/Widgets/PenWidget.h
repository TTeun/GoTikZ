//
// Created by pc on 23-10-20.
//

#ifndef GOTIKZ_PENWIDGET_H
#define GOTIKZ_PENWIDGET_H

#include "View/Widgets/ActionWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QPen>

namespace view {
    class PenWidget : public view::ActionWidget, public GroupBoxContainer {

        Q_OBJECT

      public:
        explicit PenWidget(QWidget* parent);
        PenWidget(QWidget* parent, size_t indexOfPrimitive, const QPen& pen);

      private slots:
        void setColor(const QColor& color);

      private:
        void setWidth(int width);
        void create();

        size_t m_indexOfPrimitive = std::numeric_limits<size_t>::max();
        QPen   m_pen              = QPen(Qt::black, 3);
    };
} // namespace view

#endif // GOTIKZ_PENWIDGET_H
