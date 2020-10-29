//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_XYWIDGET_H
#define GOTIKZ_XYWIDGET_H

#include <QWidget>

class QDoubleSpinBox;

namespace view {
    class XyWidget : public QWidget {

        Q_OBJECT

      public:
        explicit XyWidget(const QPointF& point, const QString& value = "");

        void setValues(const QPointF& values);

      private slots:
        void valuesChanged(int dummy);

      signals:
        void sendValues(QPointF points);

      private:
        QDoubleSpinBox* m_xButton;
        QDoubleSpinBox* m_yButton;
    };
} // namespace view

#endif // GOTIKZ_XYWIDGET_H
