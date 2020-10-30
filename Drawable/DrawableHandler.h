//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_DRAWABLEHANDLER_H
#define GOTIKZ_DRAWABLEHANDLER_H

#include "Drawable/ControlPoint/ControlPoint.h"
#include "Drawable/Drawable.h"
#include "Drawable/StreamDrawable.h"

#include <memory>
#include <vector>

class DrawableHandler {

  public:
    DrawableHandler() = default;

    void                                          addDrawable(Drawable* drawable);
    void                                          addStreamDrawable(StreamDrawable* streamDrawable);
    void                                          finalizeStreamDrawable();
    void                                          stream(const QPointF& point);
    void                                          clearSelectedAndHighlighted();
    void                                          highlightClosest(const QPointF& point);
    void                                          stopStreaming();
    void                                          setPen(const QPen& pen, size_t indexOfDrawable);
    void                                          translate(size_t indexOfPrimitive, const QPointF& translation);
    void                                          translateSelected(const QPointF& translation);
    void                                          updateControlPoints();
    bool                                          isStreaming() const;
    bool                                          addPointToStreamDrawable(const QPointF& point, bool forceEnd);
    size_t                                        indexOfSelectedDrawable() const;
    QPointF                                       snap(const QPointF& mousePoint) const;
    Drawable*                                     removeDrawable(size_t index);
    Drawable*                                     selectNew(const QPointF& point);
    Drawable*                                     addToSelected(const QPointF& point);
    Drawable*                                     getClosest(const QPointF& point);
    ControlPoint* closestControlPoint(const QPointF& mousePosition, size_t maximumDistance) const;
    const std::vector<std::unique_ptr<Drawable>>& drawables() const;
    const std::vector<Drawable*>&                 selectedDrawables() const;
    const std::vector<Drawable*>&                 highlightedDrawables() const;
    const StreamDrawable*                         streamDrawable() const;

  private:
    std::unique_ptr<StreamDrawable>            m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>>     m_drawables;
    std::vector<Drawable*>                     m_selectedDrawables;
    std::vector<Drawable*>                     m_highlightedDrawables;
    std::vector<std::unique_ptr<ControlPoint>> m_controlPoints;

  public:
    const std::vector<std::unique_ptr<ControlPoint>>& controlPoints() const;
};

#endif // GOTIKZ_DRAWABLEHANDLER_H
