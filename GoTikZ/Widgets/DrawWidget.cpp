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
    if (m_gridState.showGrid()) {
        drawGrid(&painter);
    }

    painter.setPen(QPen{Qt::black, 3});
    painter.drawLine(m_mousePoint - QPoint{0, 8}, m_mousePoint + QPoint{0, 8});
    painter.drawLine(m_mousePoint - QPoint{8, 0}, m_mousePoint + QPoint{8, 0});
    m_model->drawableHandler().draw(&painter);
}

void DrawWidget::mousePressEvent(QMouseEvent* event) {
    m_mousePoint = m_model->drawableHandler().snap(QPoint(event->localPos().x(), event->localPos().y()));
    m_actionHandler->mousePressEvent(event);
}

void DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    m_mousePoint = m_model->drawableHandler().snap(QPoint(event->localPos().x(), event->localPos().y()));
    m_actionHandler->mouseMoveEvent(event);
}

void DrawWidget::drawGrid(QPainter* painter) {
    painter->setPen(QPen{QColor{220, 221, 228}, 1});
    const auto gridSpacing = m_gridState.gridSpacing();
    for (size_t i = 0; static_cast<int>(i * gridSpacing) < width(); ++i) {
        painter->drawLine(i * gridSpacing, 0, i * gridSpacing, height());
    }
    for (size_t i = 0; static_cast<int>(i * gridSpacing) < height(); ++i) {
        painter->drawLine(0, i * gridSpacing, width(), i * gridSpacing);
    }
}

void DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
}
