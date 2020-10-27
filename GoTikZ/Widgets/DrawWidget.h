#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "ActionWidget.h"
#include "Actions/UndoableAction.h"
#include "Drawable/DrawableHandler.h"
#include "Drawable/StreamDrawable.h"

#include <QWidget>
#include <States/GridState.h>
#include <vector>

class Model;

class DrawWidget : public QWidget {
    Q_OBJECT

  public:
    DrawWidget(QWidget* parent, Model* model, ActionHandler* actionHandler);

  public:
    void setGridState(GridState newGridState);

  protected:
    void paintEvent(QPaintEvent* e) final;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

  signals:
    void updateSignal();

  private:
    void           drawGrid(QPainter* painter);
    QPointF        m_mousePoint;
    GridState      m_gridState;
    const Model*   m_model;
    ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_DRAWWIDGET_H
