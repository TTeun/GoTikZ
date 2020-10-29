//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_COLORWIDGET_H
#define GOTIKZ_COLORWIDGET_H

#include <QWidget>

class QPushButton;

namespace View {
    class ColorWidget : public QWidget {
        Q_OBJECT

      public:
        explicit ColorWidget(QWidget* parent, const QColor& color = QColor(0, 0, 0));

      private slots:
        void getColor();

      signals:
        void colorUpdated(QColor color);

      private:
        QColor       m_color;
        QPushButton* m_pushButton;
    };
} // namespace View

#endif // GOTIKZ_COLORWIDGET_H
