//
// Created by pc on 24-10-20.
//

#ifndef GOTIKZ_GROUPBOXWIDGET_H
#define GOTIKZ_GROUPBOXWIDGET_H

#include <QGroupBox>

class QWidget;
class QString;

class GroupBoxWidget {

  public:
    GroupBoxWidget(QWidget* parent, QString title);

    QGroupBox* groupBox();

    QLayout* layout();

    protected:

    QGroupBox* m_groupBox;

};

#endif // GOTIKZ_GROUPBOXWIDGET_H
