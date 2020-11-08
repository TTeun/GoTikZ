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

    void                addDrawable(Drawable* drawable);
    void                addStreamDrawable(StreamDrawable* streamDrawable);
    void                finalizeStreamDrawable();
    void                stream(const QPointF& point);
    void                clearSelectedAndHighlighted();
    void                highlightClosest(const QPointF& point);
    void                stopStreaming();
    void                setPen(const QPen& pen, size_t indexOfDrawable);
    void                translate(size_t indexOfPrimitive, const QPointF& translation);
    void                translateSelected(const QPointF& translation);
    void                translateHighlighted(const QPointF& translation);
    void                updateControlPoints();
    bool                isStreaming() const;
    bool                addPointToStreamDrawable(const QPointF& point, bool forceEnd);
    void                hideDrawable(size_t index);
    void                showDrawable(size_t index);
    std::vector<size_t> indicesOfSelectedDrawable() const;
    QPointF             snap(const QPointF& mousePoint, const double maximumSnapDistance) const;
    Drawable*           selectNew(const QPointF& point);
    Drawable*           addToSelected(const QPointF& point);
    Drawable*           getClosestDrawable(const QPointF& point);
    ControlPoint*       getClosestControlPoint(const QPointF& mousePosition, size_t maximumDistance) const;
    const std::vector<std::unique_ptr<Drawable>>& drawables() const;
    const std::vector<Drawable*>&                 selectedDrawables() const;
    const Drawable*                               highlightedDrawable() const;
    const StreamDrawable*                         streamDrawable() const;

  private:
    std::unique_ptr<StreamDrawable>            m_streamDrawable = nullptr;
    std::vector<std::unique_ptr<Drawable>>     m_drawables;
    std::vector<Drawable*>                     m_selectedDrawables;
    Drawable*                                  m_highlightedDrawable;
    std::vector<std::unique_ptr<ControlPoint>> m_controlPoints;

  public:
    const std::vector<std::unique_ptr<ControlPoint>>& controlPoints() const;
};

#endif // GOTIKZ_DRAWABLEHANDLER_H
