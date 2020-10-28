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

    void                                          addDrawable(Drawable* drawable);
    void                                          addStreamDrawable(StreamDrawable* streamDrawable);
    bool                                          isStreaming() const;
    Drawable*                                     removeDrawable(size_t index);
    const std::vector<std::unique_ptr<Drawable>>& drawables() const;
    bool                                          addPointToStreamDrawable(const QPointF& point, bool forceEnd);
    void                                          finalizeStreamDrawable();
    void                                          stream(const QPointF& point);
    QPointF                                       snap(const QPointF& mousePoint) const;
    void                                          clearSelectedAndHighlighted();
    void                                          highlightClosest(const QPointF& point);
    Drawable*                                     selectClosest(const QPointF& point);
    Drawable*                                     getClosest(const QPointF& point);
    void                                          stopStreaming();
    void                                          setPen(const QPen& pen, size_t indexOfDrawable);
    size_t                                        indexOfSelectedDrawable() const;

    const std::vector<Drawable*>& selectedDrawables() const;

    const std::vector<Drawable*>& highlightedDrawables() const;

    const StreamDrawable* streamDrawable() const;

  private:
    std::unique_ptr<StreamDrawable>        m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>> m_drawables;
    std::vector<Drawable*>                 m_selectedDrawables;
    std::vector<Drawable*>                 m_highlightedDrawables;
};

#endif // GOTIKZ_DRAWABLEHANDLER_H
