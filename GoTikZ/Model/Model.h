//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MODEL_H
#define GOTIKZ_MODEL_H

#include "Drawable/DrawableHandler.h"

#include <QMouseEvent>

class ActionHandler;

class Model {

  public:
    explicit Model(ActionHandler* actionHandler);

    const DrawableHandler& drawableHandler() const;
    DrawableHandler&       drawableHandler();
    void                   mousePressEvent(QMouseEvent* event);
    void                   mouseMoveEvent(QMouseEvent* event);
    void                   setPen(const QPen& pen);

    void setPrimitiveType(Drawable::PRIMITIVE_TYPE newType);

  private:
    DrawableHandler m_drawableHandler;
    ActionHandler*  m_actionHandler;

    QPen                     m_drawPen  = QPen(Qt::black, 3);
    Drawable::PRIMITIVE_TYPE m_drawType = Drawable::PRIMITIVE_TYPE::LINE;
};

#endif // GOTIKZ_MODEL_H
