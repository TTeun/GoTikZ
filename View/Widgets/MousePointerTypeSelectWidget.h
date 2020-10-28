//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H
#define GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H

#include "Model/MousePointerTypeEnum.h"
#include "View/Widgets/ActionWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QGroupBox>

class UndoableAction;
class QButtonGroup;
class QAbstractButton;

namespace View {
    class MousePointerTypeSelectWidget : public View::ActionWidget, public GroupBoxContainer {
      public:
        explicit MousePointerTypeSelectWidget(QWidget* parent);

        void setSelectedButton(MOUSE_POINTER_TYPE type);

      public slots:
        void mousePointerTypeButtonClicked(QAbstractButton* button);

      private:
        void addTypeButton(const QString& title, bool selected);

        QButtonGroup* m_buttonGroup;
    };
} // namespace View

#endif // GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H
