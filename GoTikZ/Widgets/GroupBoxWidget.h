//
// Created by pc on 24-10-20.
//

#ifndef GOTIKZ_GROUPBOXWIDGET_H
#define GOTIKZ_GROUPBOXWIDGET_H

class QWidget;
class QGroupBox;
class QString;

class GroupBoxWidget {

  public:
    GroupBoxWidget() = default;

    QGroupBox* init(QWidget* parent, const QString& title);
};

#endif // GOTIKZ_GROUPBOXWIDGET_H
