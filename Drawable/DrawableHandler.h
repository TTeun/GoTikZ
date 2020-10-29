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

    void      addDrawable(Drawable* drawable);
    void      addStreamDrawable(StreamDrawable* streamDrawable);
    void      finalizeStreamDrawable();
    void      stream(const QPointF& point);
    void      clearSelectedAndHighlighted();
    void      highlightClosest(const QPointF& point);
    void      stopStreaming();
    void      setPen(const QPen& pen, size_t indexOfDrawable);
    void      translateAll(const QPointF& translation);
    void      translate(size_t indexOfPrimitive, const QPointF& translation);
    void      translateSelected(const QPointF& translation);
    bool      isStreaming() const;
    bool      addPointToStreamDrawable(const QPointF& point, bool forceEnd);
    size_t    indexOfSelectedDrawable() const;
    QPointF   snap(const QPointF& mousePoint) const;
    Drawable* removeDrawable(size_t index);
    Drawable* selectClosest(const QPointF& point, bool shouldClearSelected);
    Drawable* getClosest(const QPointF& point);

    const std::vector<std::unique_ptr<Drawable>>& drawables() const;
    const std::vector<Drawable*>&                 selectedDrawables() const;
    const std::vector<Drawable*>&                 highlightedDrawables() const;
    const StreamDrawable*                         streamDrawable() const;

  private:
    std::unique_ptr<StreamDrawable>        m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>> m_drawables;
    std::vector<Drawable*>                 m_selectedDrawables;
    std::vector<Drawable*>                 m_highlightedDrawables;
};

#endif // GOTIKZ_DRAWABLEHANDLER_H
