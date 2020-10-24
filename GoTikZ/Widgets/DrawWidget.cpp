#include "DrawWidget.h"

#include "../Actions/AddPrimitiveAction.h"

#include <Drawable/Point.h>
#include <Drawable/StreamDrawableFactory.h>
#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget* parent) : ActionWidget(parent) {
    setMouseTracking(true);
}

void DrawWidget::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QBrush   brush(Qt::white);
    painter.fillRect(this->rect(), brush);
    if (m_gridState.showGrid()) {
        drawGrid(&painter);
    }

    if (m_streamDrawable) {
        m_streamDrawable->draw(&painter);
    }
    for (auto& drawable : m_drawables) {
        drawable->draw(&painter);
    }
    painter.setPen(QPen{Qt::black, 3});
    painter.drawLine(m_mousePoint - QPointF{0, 8}, m_mousePoint + QPointF{0, 8});
    painter.drawLine(m_mousePoint - QPointF{8, 0}, m_mousePoint + QPointF{8, 0});
}

void DrawWidget::mousePressEvent(QMouseEvent* event) {
    snap(event->localPos());
    if (not m_streamDrawable) {
        setStreamDrawable();
    } else {
        if (m_streamDrawable->addPoint(m_mousePoint, event->button() == Qt::RightButton)) {
            m_drawables.push_back(std::unique_ptr<Drawable>(m_streamDrawable->drawable()));
            emit undoableActionDone(new AddPrimitiveAction(m_drawables.back()->index()), true);
            m_streamDrawable.reset(nullptr);
        }
    }
    emit(updateSignal());
}

void DrawWidget::mouseMoveEvent(QMouseEvent* event) {
    snap(event->localPos());
    if (m_streamDrawable != nullptr) {
        m_streamDrawable->stream(m_mousePoint);
    }
    emit(updateSignal());
}

void DrawWidget::snap(const QPointF& mousePoint) {
    std::pair<double, QPointF> snapData{std::numeric_limits<double>::max(), mousePoint};
    if (m_streamDrawable) {
        snapData = m_streamDrawable->snap(mousePoint);
    }
    for (auto& el : m_drawables) {
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

void DrawWidget::drawGrid(QPainter* painter) {
    painter->setPen(QPen{QColor{220, 221, 228}, 1});
    const auto gridSpacing = m_gridState.gridSpacing();
    for (size_t i = 0; static_cast<int>(i * gridSpacing) < width(); ++i) {
        painter->drawLine(i * gridSpacing, 0, i * gridSpacing, height());
    }
    for (size_t i = 0; static_cast<int>(i * gridSpacing) < width(); ++i) {
        painter->drawLine(0, i * gridSpacing, width(), i * gridSpacing);
    }
}

void DrawWidget::setStreamDrawable() {
    switch (m_drawType) {
        case PRIMITIVE_TYPE::POINT:
            m_drawables.push_back(std::unique_ptr<Drawable>(new Point(m_mousePoint, m_pen)));
            emit undoableActionDone(new AddPrimitiveAction(m_drawables.back()->index()), true);
            break;
        default:
            m_streamDrawable.reset(StreamDrawableFactory::make(m_mousePoint, m_drawType, m_pen));
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
    m_drawables.push_back(std::unique_ptr<Drawable>(drawable));
    emit(updateSignal());
}

Drawable* DrawWidget::removeDrawable(const size_t index) {
    Drawable* returnPointer = nullptr;
    for (auto it = m_drawables.begin(); it != m_drawables.end(); ++it) {
        if ((*it)->index() == index) {
            returnPointer = it->release();
            m_drawables.erase(it);
            break;
        }
    }
    assert(returnPointer != nullptr);
    emit(updateSignal());
    return returnPointer;
}
void DrawWidget::setGridState(GridState newGridState) {
    m_gridState = newGridState;
    emit(updateSignal());
}

void DrawWidget::setPen(QPen pen) {
    m_pen = pen;
}
