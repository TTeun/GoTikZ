#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "ActionWidget.h"
#include "Actions/UndoableAction.h"
#include "Drawable/DrawableHandler.h"
#include "Drawable/StreamDrawable.h"

#include <QWidget>
#include <States/GridState.h>
#include <vector>

class DrawWidget : public QWidget {
    Q_OBJECT

  signals:
    void undoableActionDone(UndoableAction* action, bool isAlreadyDone);
    void actionDone(Action* action);

  public:
    explicit DrawWidget(QWidget* parent);

    void      addDrawable(Drawable* drawable);
    Drawable* removeDrawable(size_t index);
    enum class PRIMITIVE_TYPE { LINE, POINT, CIRCLE, POLY_LINE };
    PRIMITIVE_TYPE primitiveType() const;

  public slots:
    void setPrimitiveType(PRIMITIVE_TYPE newType);
    void setGridState(GridState newGridState);
    void setPen(QPen pen);

  protected:
    void paintEvent(QPaintEvent* e) final;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

  signals:
    void updateSignal();

  private:
    void           drawGrid(QPainter* painter);
    void           setStreamDrawable();
    QPointF        m_mousePoint;
    GridState      m_gridState;
    PRIMITIVE_TYPE m_drawType = PRIMITIVE_TYPE::LINE;
    QPen           m_drawPen  = QPen(Qt::black, 3);

    DrawableHandler m_drawableHandler;
};

#endif // GOTIKZ_DRAWWIDGET_H
