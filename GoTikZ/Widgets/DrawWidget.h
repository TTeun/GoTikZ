#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

#include "Drawable/StreamDrawable.h"

#include <vector>

class DrawWidget : public QWidget {
  Q_OBJECT
public:
  explicit DrawWidget(QWidget *parent = nullptr);

  enum class DRAW_TYPE { LINE, POINT, CIRCLE, POLY_LINE };

public slots:
  void typeChanged(DRAW_TYPE type);
  void colorChanged(const QColor &color);
  void showGrid(bool show);
  void setGridSpacing(int spacing);

protected:
  void paintEvent(QPaintEvent *e) final;

  void mousePressEvent(QMouseEvent *event) override;

  void mouseMoveEvent(QMouseEvent *event) override;

signals:

  void updateSignal();

private:
  void drawGrid(QPainter *painter);

  void snap(const QPointF &mousePoint);

  void setStreamDrawable();

  std::unique_ptr<StreamDrawable> m_streamDrawable = nullptr;

  std::vector<std::unique_ptr<Drawable>> m_drawables;

  DRAW_TYPE m_drawType = DRAW_TYPE::LINE;

  QPointF m_mousePoint;

  QColor m_color = QColor{0, 0, 0};

  bool m_showGrid;
  int m_gridSize = 10;
};

#endif // DRAWWIDGET_H
