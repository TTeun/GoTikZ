//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_COLORWIDGET_H
#define GOTIKZ_COLORWIDGET_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class ColorWidget : public QWidget {
  Q_OBJECT

public:
  ColorWidget(QWidget *parent = 0);

private slots:
  void getColor();

signals:
  void colorUpdated(QColor color);

private:
  QColor m_color;
  QPushButton *m_pushButton;
};

#endif // GOTIKZ_COLORWIDGET_H
