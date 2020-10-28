#include "DrawWidget.h"

#include "../Math/Math.h"
#include "Actions/ActionHandler.h"
#include "Model/Model.h"

#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget* parent, Model* model, ActionHandler* actionHandler)
    : QWidget(parent), m_model(model), m_actionHandler(actionHandler) {

    assert(m_model);
    assert(m_actionHandler);
    setMouseTracking(true);
}

void DrawWidget::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QBrush   brush(Qt::white);
    painter.fillRect(this->rect(), brush);
    painter.save();
    if (m_gridState.showGrid()) {
        drawGrid(&painter);
    }

    m_transform.applyTransform(painter);
    painter.setPen(QPen{Qt::black, 3});
    m_model->drawableHandler().draw(&painter);

    painter.restore();
    painter.setPen(QPen{Qt::black, 2});
    painter.drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
    painter.drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}

void DrawWidget::drawGrid(QPainter* painter) {
    painter->setPen(QPen{QColor{220, 221, 228}, 1});
    const double scale             = m_transform.scale();
    const int    dx                = m_transform.translation().x();
    const int    dy                = m_transform.translation().y();
    const int    gridSpacing       = m_gridState.gridSpacing();
    const int    scaledGridSpacing = gridSpacing * scale;

    for (int i = -dy / scaledGridSpacing; dy + i * scaledGridSpacing < height(); ++i) {
        painter->drawLine(0, dy + i * scaledGridSpacing, width(), dy + i * scaledGridSpacing);
    }
    for (int i = -dx / scaledGridSpacing; dx + i * scaledGridSpacing < width(); ++i) {
        painter->drawLine(dx + i * scaledGridSpacing, 0, dx + i * scaledGridSpacing, height());
    }

    painter->setPen(QPen{Qt::black, 3});
    const int sideLineInterval = std::max(1, 150 / scaledGridSpacing);
    const int i_start          = -dy / scaledGridSpacing;
    for (int i = sideLineInterval * std::floor(i_start / sideLineInterval); dy + i * scaledGridSpacing < height();
         i += sideLineInterval) {
        painter->drawLine(0, dy + i * scaledGridSpacing, 5, dy + i * scaledGridSpacing);
        painter->drawText(10, dy + i * scaledGridSpacing + 6, QString::number(i * gridSpacing, 10));
        painter->drawLine(width() - 5, dy + i * scaledGridSpacing, width(), dy + i * scaledGridSpacing);
    }
    const int j_start = -dx / scaledGridSpacing;
    for (int j = sideLineInterval * std::floor(j_start / sideLineInterval); dx + j * scaledGridSpacing < width();
         j += sideLineInterval) {
        painter->drawLine(dx + j * scaledGridSpacing, 0, dx + j * scaledGridSpacing, 5);
        painter->drawText(dx + j * scaledGridSpacing, 20, QString::number(j * gridSpacing, 10));
        painter->drawLine(dx + j * scaledGridSpacing, height() - 5, dx + j * scaledGridSpacing, height());
    }

    painter->drawLine(0, 0, width(), 0);
    painter->drawLine(0, height(), width(), height());
    painter->drawLine(0, 0, 0, height());
    painter->drawLine(width(), 0, width(), height());
}

void DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
}

void DrawWidget::mousePressEvent(QMouseEvent* event) {
    m_mousePoint = m_model->drawableHandler().snap(event->localPos());
    m_actionHandler->mousePressEvent(event);
}

void DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    m_mousePoint = m_model->drawableHandler().snap(event->localPos());
    m_actionHandler->mouseMoveEvent(event);
}

void DrawWidget::wheelEvent(QWheelEvent* event) {
    m_actionHandler->wheelEvent(event);
}

Transform& DrawWidget::transform() {
    return m_transform;
}
