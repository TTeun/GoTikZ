//
// Created by pc on 16-10-20.
//

#ifndef GOTIKZ_PRIMITIVESELECTWIDGET_H
#define GOTIKZ_PRIMITIVESELECTWIDGET_H

#include "ActionWidget.h"
#include "DrawWidget.h"
#include "GroupBoxWidget.h"

#include <QGroupBox>

class UndoableAction;
class QButtonGroup;
class QAbstractButton;

class PrimitiveSelectWidget : public ActionWidget {
  public:
    explicit PrimitiveSelectWidget(QWidget* parent);

    void setSelectedButton(DrawWidget::PRIMITIVE_TYPE type);

    QGroupBox* m_groupBox;


  public slots:
    void primitiveSelected(QAbstractButton* button);

  private:
    void addTypeButton( const QString& title, bool selected);

    QButtonGroup* m_buttonGroup;
};

#endif // GOTIKZ_PRIMITIVESELECTWIDGET_H
