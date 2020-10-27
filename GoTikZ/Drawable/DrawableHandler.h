//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_DRAWABLEHANDLER_H
#define GOTIKZ_DRAWABLEHANDLER_H

#include "Drawable.h"
#include "StreamDrawable.h"

#include <memory>
#include <vector>

class DrawableHandler {

  public:
    DrawableHandler() = default;

    void draw(QPainter* painter);

    void addDrawable(Drawable* drawable);

    void addStreamDrawable(StreamDrawable* streamDrawable);

    bool isStreaming();

    Drawable* removeDrawable(size_t index);

    const std::vector<std::unique_ptr<Drawable>>& drawables();

    bool addPointToStreamDrawable(const QPointF& point, bool forceEnd);

    void finalizeStreamDrawable();

    void stream(const QPointF& point);

    QPointF snap(const QPointF& mousePoint);

  private:
    std::unique_ptr<StreamDrawable>        m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>> m_drawables;
};

#endif // GOTIKZ_DRAWABLEHANDLER_H
