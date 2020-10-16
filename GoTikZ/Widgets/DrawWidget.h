#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include "ActionWidget.h"
#include "Drawable/StreamDrawable.h"

#include <Actions/Action.h>
#include <QWidget>
#include <vector>

class AddPrimitiveAction;

class DrawWidget : public ActionWidget {
    Q_OBJECT
  public:
    explicit DrawWidget(QWidget* parent = nullptr);

    enum class PRIMITIVE_TYPE { LINE, POINT, CIRCLE, POLY_LINE };

  public slots:
    void colorChanged(const QColor& color);
    void showGrid(bool show);
    void setGridSpacing(int spacing);

    void setPrimitiveType(PRIMITIVE_TYPE newType) {
        m_drawType = newType;
    }

    PRIMITIVE_TYPE primitiveType() const {
        return m_drawType;
    }

  protected:
    void paintEvent(QPaintEvent* e) final;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

  signals:
    void updateSignal();

  private:
    void drawGrid(QPainter* painter);

    void snap(const QPointF& mousePoint);

    void setStreamDrawable();

    friend class AddPrimitiveAction;
    std::unique_ptr<StreamDrawable>        m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>> m_drawables;
    PRIMITIVE_TYPE                         m_drawType = PRIMITIVE_TYPE::LINE;
    QPointF                                m_mousePoint;
    QColor                                 m_color    = QColor{0, 0, 0};
    bool                                   m_showGrid = true;
    int                                    m_gridSize = 10;
};

#endif // DRAWWIDGET_H
