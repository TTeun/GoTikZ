#include "drawwidget.h"

#include <Drawable/Point.h>
#include <Drawable/StreamDrawableFactory.h>
#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) {
  setMouseTracking(true);
}

void DrawWidget::paintEvent(QPaintEvent *e) {
  QPainter painter(this);
  if (m_streamDrawable) {
    m_streamDrawable->draw(&painter);
  }
  for (auto &drawable : m_drawables) {
    drawable->draw(&painter);
  }
  painter.setPen(QPen{Qt::black, 3});
  painter.drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
  painter.drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}

void DrawWidget::mousePressEvent(QMouseEvent *event) {
  snap(event->localPos());
  if (not m_streamDrawable) {
    switch (m_drawType) {
    case DRAW_TYPE::POINT:
      m_drawables.push_back(
          std::unique_ptr<Drawable>(new Point(m_mousePoint, m_color)));
      break;
    default:
      m_streamDrawable.reset(
          StreamDrawableFactory::make(m_mousePoint, m_drawType, m_color));
      break;
    }
  } else {
    if (m_streamDrawable->addPoint(m_mousePoint,
                                   event->button() == Qt::RightButton)) {
      m_drawables.push_back(
          std::unique_ptr<Drawable>(m_streamDrawable->drawable()));
      m_streamDrawable.reset(nullptr);
    }
  }
  emit(updateSignal());
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event) {
  snap(event->localPos());
  if (m_streamDrawable != nullptr) {
    m_streamDrawable->stream(m_mousePoint);
  }
  emit(updateSignal());
}

void DrawWidget::typeChanged(DrawWidget::DRAW_TYPE type) {
  if (type == m_drawType) {
    return;
  }
  m_drawType = type;
  if (m_streamDrawable) {
    m_streamDrawable.reset(nullptr);
    updateSignal();
  }
}

void DrawWidget::snap(const QPointF &mousePoint) {
  std::pair<double, QPointF> snapData{std::numeric_limits<double>::max(),
                                      mousePoint};
  if (m_streamDrawable) {
    snapData = m_streamDrawable->snap(mousePoint);
  }
  for (auto &el : m_drawables) {
    const auto currentSnap = el->snap(mousePoint);
    if (currentSnap.first < snapData.first) {
      snapData = currentSnap;
    }
  }
  if (snapData.first < 20) {
    m_mousePoint = snapData.second;
  } else {
    m_mousePoint = mousePoint;
  }
}
void DrawWidget::colorChanged(QColor color) {
  m_color = color;

  qDebug() << "Asdsadd";
}
