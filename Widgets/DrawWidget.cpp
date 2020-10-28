#include "DrawWidget.h"

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
    painter.setPen(QPen{Qt::black, 3});

    const auto& drawableHandler = m_model->drawableHandler();

    for (const auto& el : drawableHandler.selectedDrawables()) {
        el->draw(&painter, Drawable::DRAW_FLAGS::SELECTED, m_transform);
    }

    for (const auto& el : drawableHandler.drawables()) {
        el->draw(&painter, Drawable::DRAW_FLAGS::NONE, m_transform);
    }

    for (const auto& el : drawableHandler.highlightedDrawables()) {
        el->draw(&painter, Drawable::DRAW_FLAGS::HIGHLIGHTED, m_transform);
    }

    if (drawableHandler.isStreaming()) {
        drawableHandler.streamDrawable()->draw(&painter, Drawable::DRAW_FLAGS::NONE, m_transform);
    }

    painter.restore();
    drawMousePointer(&painter);
}

void DrawWidget::drawGrid(QPainter* painter) {
    painter->setPen(QPen{QColor{220, 221, 228}, 1});
    const double scale             = m_transform.scale();
    const int    dx                = m_transform.translation().x();
    const int    dy                = m_transform.translation().y();
    const int    gridSpacing       = m_gridState.gridSpacing();
    const int    scaledGridSpacing = gridSpacing * scale;

    if (scaledGridSpacing == 0) {
        return;
    }

    for (int i = -dy / scaledGridSpacing; dy + i * scaledGridSpacing < height(); ++i) {
        painter->drawLine(0, dy + i * scaledGridSpacing, width(), dy + i * scaledGridSpacing);
    }
    for (int i = -dx / scaledGridSpacing; dx + i * scaledGridSpacing < width(); ++i) {
        painter->drawLine(dx + i * scaledGridSpacing, 0, dx + i * scaledGridSpacing, height());
    }

    painter->setPen(QPen{Qt::black, 3});
    int sideLineInterval = 1;
    while (sideLineInterval * scaledGridSpacing < 70) {
        sideLineInterval *= 2;
        assert(sideLineInterval < std::numeric_limits<int>::max() / 4);
    }

    const int i_start = -dy / scaledGridSpacing;
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

    painter->setPen(QPen{QColor(190, 190, 190), 1, Qt::DashLine});
    painter->drawLine(0, m_mousePoint.y(), width(), m_mousePoint.y());
    painter->drawLine(m_mousePoint.x(), 0, m_mousePoint.x(), height());
}

void DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
}

void DrawWidget::mousePressEvent(QMouseEvent* event) {
    m_mousePoint = event->localPos();
    m_actionHandler->mousePressEvent(event);
}

void DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    m_mousePoint = event->localPos();
    m_actionHandler->mouseMoveEvent(event);
}

void DrawWidget::wheelEvent(QWheelEvent* event) {
    m_actionHandler->wheelEvent(event, m_mousePoint);
}

Transform& DrawWidget::transform() {
    return m_transform;
}

void DrawWidget::drawMousePointer(QPainter* painter) {
    const auto snappedMousePoint = m_transform.applyTransform(
        m_model->drawableHandler().snap(m_model->mousePointInWorldCoordinates(m_mousePoint)));
    painter->setPen(QPen{Qt::gray, 1});
    painter->drawLine(snappedMousePoint - QPointF{0, 8}, snappedMousePoint + QPointF{0, 8});
    painter->drawLine(snappedMousePoint - QPointF{8, 0}, snappedMousePoint + QPointF{8, 0});

    painter->setPen(QPen{Qt::black, 3});
    painter->drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
    painter->drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}
