#include "DrawWidget.h"

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/Transform.h"

#include <QMouseEvent>
#include <QPainter>
#include <cmath>

view::DrawWidget::DrawWidget(QWidget* parent, const model::Model* model, controller::Controller* actionHandler)
    : QWidget(parent), m_modelHandler(model), m_actionHandler(actionHandler) {
    setMouseTracking(true);
}

void view::DrawWidget::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QBrush   brush(Qt::white);
    painter.fillRect(this->rect(), brush);
    if (m_gridState.showGrid()) {
        drawGrid(&painter);
    }
    painter.setPen(QPen{Qt::black, 3});

    const auto& drawableHandler = m_modelHandler->drawableHandler();

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

    drawMousePointer(&painter);
}

void view::DrawWidget::drawGrid(QPainter* painter) {
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

    const int iStart = -dy / scaledGridSpacing;
    for (int i = sideLineInterval * std::floor(iStart / sideLineInterval); dy + i * scaledGridSpacing < height();
         i += sideLineInterval) {
        painter->drawLine(0, dy + i * scaledGridSpacing, 5, dy + i * scaledGridSpacing);
        painter->drawText(10, dy + i * scaledGridSpacing + 6, QString::number(i * gridSpacing, 10));
        painter->drawLine(width() - 5, dy + i * scaledGridSpacing, width(), dy + i * scaledGridSpacing);
    }

    const int jStart = -dx / scaledGridSpacing;
    for (int j = sideLineInterval * std::floor(jStart / sideLineInterval); dx + j * scaledGridSpacing < width();
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

void view::DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
}

void view::DrawWidget::mousePressEvent(QMouseEvent* event) {
    m_mousePoint = event->localPos();
    m_actionHandler->mousePressEvent(event);
}

void view::DrawWidget::mouseReleaseEvent(QMouseEvent* event) {
    m_mousePoint = event->localPos();
    m_actionHandler->mouseReleaseEvent(event);
}

void view::DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    m_mousePoint = event->localPos();
    m_actionHandler->mouseMoveEvent(event);
}

void view::DrawWidget::wheelEvent(QWheelEvent* event) {
    m_actionHandler->wheelEvent(event, m_mousePoint);
}

view::Transform& view::DrawWidget::transform() {
    return m_transform;
}

void view::DrawWidget::drawMousePointer(QPainter* painter) {
    const auto snappedMousePoint = m_transform.applyTransform(
        m_modelHandler->drawableHandler().snap(m_modelHandler->mousePointInWorldCoordinates(m_mousePoint)));
    painter->setPen(QPen{Qt::gray, 1});
    painter->drawLine(snappedMousePoint - QPointF{0, 8}, snappedMousePoint + QPointF{0, 8});
    painter->drawLine(snappedMousePoint - QPointF{8, 0}, snappedMousePoint + QPointF{8, 0});

    painter->setPen(QPen{Qt::black, 3});
    painter->drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
    painter->drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}
