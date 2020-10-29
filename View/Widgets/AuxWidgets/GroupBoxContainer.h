//
// Created by pc on 24-10-20.
//

#ifndef GOTIKZ_GROUPBOXCONTAINER_H
#define GOTIKZ_GROUPBOXCONTAINER_H

#include <QDebug>

class QWidget;
class QString;
class QGroupBox;

class GroupBoxContainer {

  public:
    GroupBoxContainer(QWidget* parent, QString title);

  protected:
    QGroupBox* m_groupBox;
};

#endif // GOTIKZ_GROUPBOXCONTAINER_H
