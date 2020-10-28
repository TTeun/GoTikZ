//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H
#define GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H

#include "ActionWidget.h"
#include "Model/MousePointerTypeEnum.h"
#include "Widgets/AuxWidgets/GroupBoxContainer.h"

#include <QGroupBox>

class UndoableAction;
class QButtonGroup;
class QAbstractButton;

class MousePointerTypeSelectWidget : public ActionWidget, public GroupBoxContainer {
  public:
    explicit MousePointerTypeSelectWidget(QWidget* parent);

    void setSelectedButton(MOUSE_POINTER_TYPE type);

  public slots:
    void mousePointerTypeButtonClicked(QAbstractButton* button);

  private:
    void addTypeButton(const QString& title, bool selected);

    QButtonGroup* m_buttonGroup;
};

#endif // GOTIKZ_MOUSEPOINTERTYPESELECTWIDGET_H
