#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "ActionWidget.h"
#include "States/GridState.h"

#include <QWidget>

class Model;
class ActionHandler;

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
    QPoint        m_mousePoint;
    GridState      m_gridState;
    const Model*   m_model;
    ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_DRAWWIDGET_H
