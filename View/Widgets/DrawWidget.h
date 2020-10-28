#ifndef GOTIKZ_DRAWWIDGET_H
#define GOTIKZ_DRAWWIDGET_H

#include "Controller/Actions/ActionHandler.h"
#include "View/GridState.h"
#include "View/Transform.h"
#include "View/Widgets/ActionWidget.h"

#include <QWidget>

class Model;
namespace Controller {
    class ActionHandler;
}

namespace View {
    class DrawWidget : public QWidget {
        Q_OBJECT

      public:
        DrawWidget(QWidget* parent, Model* model, Controller::ActionHandler* actionHandler);

      public:
        void       setGridState(GridState newGridState);
        Transform& transform();

      protected:
        void paintEvent(QPaintEvent* e) final;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
        void wheelEvent(QWheelEvent* event) override;

      private:
        void drawGrid(QPainter* painter);
        void drawMousePointer(QPainter* painter);

        QPointF                    m_mousePoint;
        GridState                  m_gridState;
        Transform                  m_transform;
        const Model*               m_model;
        Controller::ActionHandler* m_actionHandler;
    };
} // namespace View

#endif // GOTIKZ_DRAWWIDGET_H
