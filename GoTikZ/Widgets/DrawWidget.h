#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include "ActionWidget.h"
#include "Actions/UndoableAction.h"
#include "Drawable/StreamDrawable.h"

#include <QWidget>
#include <States/GridState.h>
#include <vector>

class DrawWidget : public ActionWidget {
    Q_OBJECT
  public:
    explicit DrawWidget(QWidget* parent = nullptr);

    void      addDrawable(Drawable* drawable);
    Drawable* removeDrawable(const size_t index);
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
    void drawGrid(QPainter* painter);
    void snap(const QPointF& mousePoint);
    void setStreamDrawable();

    std::unique_ptr<StreamDrawable>        m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>> m_drawables;
    PRIMITIVE_TYPE                         m_drawType = PRIMITIVE_TYPE::LINE;
    QPointF                                m_mousePoint;
    GridState                              m_gridState;
    QPen                                   m_pen;
};

#endif // DRAWWIDGET_H
