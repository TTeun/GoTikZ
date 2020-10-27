#include "DrawWidget.h"

#include "../Actions/AddPrimitiveAction.h"

#include <Drawable/Point.h>
#include <Drawable/StreamDrawableFactory.h>
#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget* parent) : QWidget(parent) {
    setMouseTracking(true);
}

void DrawWidget::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QBrush   brush(Qt::white);
    painter.fillRect(this->rect(), brush);
    if (m_gridState.showGrid()) {
        drawGrid(&painter);
    }

    m_drawableHandler.draw(&painter);
    //    if (m_streamDrawable) {
    //        m_streamDrawable->draw(&painter);
    //    }
    //    for (auto& drawable : m_drawables) {
    //        drawable->draw(&painter);
    //    }
    painter.setPen(QPen{Qt::black, 3});
    painter.drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
    painter.drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}

void DrawWidget::mousePressEvent(QMouseEvent* event) {
    m_mousePoint = m_drawableHandler.snap(event->localPos());
    if (not m_drawableHandler.isStreaming()) {
        setStreamDrawable();
    } else {
        if (m_drawableHandler.addPointToStreamDrawable(m_mousePoint, event->button() == Qt::RightButton)) {
            emit undoableActionDone(new AddPrimitiveAction(m_drawableHandler.drawables().back()->index()), true);
        }
    }
    emit(updateSignal());
}

void DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    m_mousePoint = m_drawableHandler.snap(event->localPos());
    if (m_drawableHandler.isStreaming()) {
        m_drawableHandler.stream(m_mousePoint);
    }
    emit(updateSignal());
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

void DrawWidget::setStreamDrawable() {
    switch (m_drawType) {
        case PRIMITIVE_TYPE::POINT:
            m_drawableHandler.addDrawable(new Point(m_mousePoint, m_drawPen));
            emit undoableActionDone(new AddPrimitiveAction(m_drawableHandler.drawables().back()->index()), true);
            break;
        default:
            m_drawableHandler.addStreamDrawable(StreamDrawableFactory::make(m_mousePoint, m_drawType, m_drawPen));
            break;
    }
    emit(updateSignal());
}

void DrawWidget::setPrimitiveType(DrawWidget::PRIMITIVE_TYPE newType) {
    m_drawType = newType;
}

DrawWidget::PRIMITIVE_TYPE DrawWidget::primitiveType() const {
    return m_drawType;
}

void DrawWidget::addDrawable(Drawable* drawable) {
    m_drawableHandler.addDrawable(drawable);
    emit(updateSignal());
}

Drawable* DrawWidget::removeDrawable(const size_t index) {
    return m_drawableHandler.removeDrawable(index);
}

void DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
    emit(updateSignal());
}

void DrawWidget::setPen(QPen pen) {
    m_drawPen = pen;
}
