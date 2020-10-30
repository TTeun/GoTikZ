//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_PRIMITIVETYPESELECTWIDGET_H
#define GOTIKZ_PRIMITIVETYPESELECTWIDGET_H

#include "Model/PrimitiveTypeEnum.h"
#include "View/Widgets/ActionWidget.h"
#include "View/Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QGroupBox>

class QButtonGroup;
class QAbstractButton;

namespace view {
    class PrimitiveTypeSelectWidget : public view::ActionWidget, public GroupBoxContainer {
      public:
        explicit PrimitiveTypeSelectWidget(QWidget* parent);

        void setSelectedButton(PRIMITIVE_TYPE type);

      public slots:
        void mousePointerTypeButtonClicked(QAbstractButton* button);

      private:
        void addTypeButton(const QString& title, bool selected);

        QButtonGroup* m_buttonGroup;
    };
} // namespace view

#endif // GOTIKZ_PRIMITIVETYPESELECTWIDGET_H
