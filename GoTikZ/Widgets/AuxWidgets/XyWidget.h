//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_XYWIDGET_H
#define GOTIKZ_XYWIDGET_H

#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class XyWidget : public QWidget {

    Q_OBJECT

  public:
    explicit XyWidget(const QPointF& point, const QString& value = "");

  private slots:
    void valuesChanged(int dummy);

  signals:
    void sendValues(QPointF points);

  private:
    QSpinBox* m_xButton;
    QSpinBox* m_yButton;
};

#endif // GOTIKZ_XYWIDGET_H
