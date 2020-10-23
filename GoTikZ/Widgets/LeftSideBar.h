//
// Created by pc on 15-10-20.
//

#ifndef GOTIKZ_LEFTSIDEBAR_H
#define GOTIKZ_LEFTSIDEBAR_H

#include "GridSettingWidget.h"
#include "PenWidget.h"
#include "PrimitiveSelectWidget.h"
#include "Widgets/DrawWidget.h"

#include <QWidget>

class QRadioButton;
class ColorWidget;
class QButtonGroup;
class QAbstractButton;
class QGroupBox;
class QSpinBox;

class LeftSideBar : public QWidget {
    Q_OBJECT

  public:
    explicit LeftSideBar(QWidget* parent = 0);
    PrimitiveSelectWidget* m_primitiveSelectionWidget;
    GridSettingWidget*     m_gridSettingWidget;
    PenWidget*             m_penWidget;

    PrimitiveSelectWidget* primitiveSelectWidget() const {
        return m_primitiveSelectionWidget;
    }

    GridSettingWidget* gridSettingWidget() const {
        return m_gridSettingWidget;
    }

    PenWidget* penWidget() const {
        return m_penWidget;
    }
};

#endif // GOTIKZ_LEFTSIDEBAR_H
