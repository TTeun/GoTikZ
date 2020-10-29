#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "View/GridState.h"
#include "View/Transform.h"

#include <QWidget>

namespace Model {
    class ModelHandler;
}

namespace Controller {
    class ActionHandler;
}

namespace View {
    class DrawWidget : public QWidget {
        Q_OBJECT

      public:
        DrawWidget(QWidget* parent, const Model::ModelHandler* model, Controller::ActionHandler* actionHandler);

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

        const Model::ModelHandler* m_modelHandler;
        Controller::ActionHandler* m_actionHandler;
    };
} // namespace View

#endif // GOTIKZ_DRAWWIDGET_H
