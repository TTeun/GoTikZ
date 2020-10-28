#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "ActionWidget.h"
#include "States/GridState.h"
#include "States/Transform.h"

#include <QWidget>

class Model;
class ActionHandler;

class DrawWidget : public QWidget {
    Q_OBJECT

  public:
    DrawWidget(QWidget* parent, Model* model, ActionHandler* actionHandler);

  public:
    void       setGridState(GridState newGridState);
    Transform& transform();

  protected:
    void paintEvent(QPaintEvent* e) final;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

  private:
    void drawGrid(QPainter* painter);

    QPointF        m_mousePoint;
    GridState      m_gridState;
    Transform      m_transform;
    const Model*   m_model;
    ActionHandler* m_actionHandler;
};

#endif // GOTIKZ_DRAWWIDGET_H
