//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_PRIMITIVESELECTWIDGET_H
#define GOTIKZ_PRIMITIVESELECTWIDGET_H

#include "ActionWidget.h"
#include "DrawWidget.h"

#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>

class UndoableAction;

class PrimitiveSelectWidget : public ActionWidget {
  public:
    explicit PrimitiveSelectWidget(QWidget* parent = 0);
    void setSelectedButton(DrawWidget::PRIMITIVE_TYPE type);


  public slots:
    void primitiveSelected(QAbstractButton* button);

  private:
    void addTypeButton(QGroupBox* groupbox, const QString& title, bool selected);

    QButtonGroup* m_buttonGroup;
};

#endif // GOTIKZ_PRIMITIVESELECTWIDGET_H
