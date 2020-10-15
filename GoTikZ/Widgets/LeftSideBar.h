//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include <QWidget>

#include <QDebug>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QGroupBox>

#include "ColorWidget.h"
#include "Widgets/drawwidget.h"

class LeftSideBar : public QWidget {
  Q_OBJECT

public:
  explicit LeftSideBar(QWidget *parent = 0);
  QButtonGroup *m_buttonGroup;
  ColorWidget *m_colorWidget;

signals:
  void typeChanged(DrawWidget::DRAW_TYPE type);

public slots:

  void typeClicked(QAbstractButton *button);

private:
  void buildTypeGroupBox();
  void buildPenGroupBox();

  void addTypeButton(QGroupBox *groupbox, QButtonGroup *buttonGroup,
                     const QString &title, bool selected);

};

#endif // GOTIKZ_LEFTSIDEBAR_H
