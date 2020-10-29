#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "View/GridState.h"
#include "View/Transform.h"

#include <QWidget>

namespace model {
    class Model;
}

namespace controller {
    class Controller;
}

namespace view {
    class DrawWidget : public QWidget {
        Q_OBJECT

      public:
        DrawWidget(QWidget* parent, const model::Model* model, controller::Controller* actionHandler);

      public:
        void             setGridState(GridState newGridState);
        Transform&       transform();
        const Transform& transform() const;

      protected:
        void paintEvent(QPaintEvent* e) final;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
        void wheelEvent(QWheelEvent* event) override;

      private:
        void drawGrid(QPainter* painter);
        void drawMousePointer(QPainter* painter);

        QPointF   m_mousePoint;
        GridState m_gridState;
        Transform m_transform;

        const model::Model* m_modelHandler;
        controller::Controller* m_actionHandler;
    };
} // namespace view

#endif // GOTIKZ_DRAWWIDGET_H
