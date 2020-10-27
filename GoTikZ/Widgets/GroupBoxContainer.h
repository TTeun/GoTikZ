//
// Created by pc on 24-10-20.
//

#ifndef GOTIKZ_GROUPBOXCONTAINER_H
#define GOTIKZ_GROUPBOXCONTAINER_H

#include <QDebug>
#include <QGroupBox>

class QWidget;
class QString;
class QLayout;

class GroupBoxContainer {

  public:
    GroupBoxContainer(QWidget* parent, QString title);

    ~GroupBoxContainer() {
        qDebug() << "dood\n";
    }

    QGroupBox* groupBox();

    QLayout* layout();

  private:
    QGroupBox* m_groupBox;
};

#endif // GOTIKZ_GROUPBOXCONTAINER_H
