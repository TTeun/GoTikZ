//
// Created by pc on 27-10-20.
//

#include "DrawableHandler.h"

#include <QPainter>

void DrawableHandler::addDrawable(Drawable* drawable) {
    m_drawables.push_back(std::unique_ptr<Drawable>(drawable));
}

void DrawableHandler::addStreamDrawable(StreamDrawable* streamDrawable) {
    assert(m_streamDrawable == nullptr);
    m_streamDrawable.reset(streamDrawable);
}

bool DrawableHandler::isStreaming() const {
    return m_streamDrawable != nullptr;
}

Drawable* DrawableHandler::removeDrawable(const size_t index) {
    Drawable* returnPointer = nullptr;
    for (auto it = m_drawables.begin(); it != m_drawables.end(); ++it) {
        if ((*it)->index() == index) {
            returnPointer = it->release();
            m_drawables.erase(it);
            break;
        }
    }
    assert(returnPointer != nullptr);
    return returnPointer;
}

const std::vector<std::unique_ptr<Drawable>>& DrawableHandler::drawables() const {
    return m_drawables;
}

bool DrawableHandler::addPointToStreamDrawable(const QPointF& point, bool forceEnd) {
    assert(m_streamDrawable);
    bool streamingDone = m_streamDrawable->addPoint(point, forceEnd);
    if (streamingDone) {
        finalizeStreamDrawable();
        assert(not m_streamDrawable);
    }
    return streamingDone;
}

void DrawableHandler::finalizeStreamDrawable() {
    addDrawable(m_streamDrawable->drawable());
    m_streamDrawable.reset(nullptr);
}

void DrawableHandler::stream(const QPointF& point) {
    assert(m_streamDrawable);
    m_streamDrawable->stream(point);
}

QPointF DrawableHandler::snap(const QPointF& mousePoint) const {
    std::pair<double, QPointF> snapData(std::numeric_limits<double>::max(), mousePoint);
    if (m_streamDrawable) {
        snapData = m_streamDrawable->snap(mousePoint);
    }
    for (auto& el : m_drawables) {
        const auto currentSnap = el->snap(mousePoint);
        if (currentSnap.first < snapData.first) {
            snapData = currentSnap;
        }
    }
    if (snapData.first < 20) {
        return snapData.second;
    } else {
        return mousePoint;
    }
}

void DrawableHandler::clearSelectedAndHighlighted() {
    m_selectedDrawables.clear();
    m_highlightedDrawables.clear();
}

void DrawableHandler::highlightClosest(const QPointF& point) {
    auto* closest = getClosest(point);
    if (closest == nullptr) {
        return;
    }
    if (std::find(m_selectedDrawables.begin(), m_selectedDrawables.end(), closest) == m_selectedDrawables.end()) {
        m_highlightedDrawables = {closest};
    } else {
        m_highlightedDrawables.clear();
    }
}

Drawable* DrawableHandler::getClosest(const QPointF& point) {
    if (m_drawables.empty()) {
        return nullptr;
    }
    Drawable* closest = m_drawables.front().get();
    for (const auto& el : m_drawables) {
        if (el->dist(point) < closest->dist(point)) {
            closest = el.get();
        }
    }
    return closest;
}

Drawable* DrawableHandler::selectClosest(const QPointF& point) {
    auto* closest = getClosest(point);
    if (closest == nullptr) {
        return nullptr;
    }
    m_selectedDrawables = {closest};
    m_highlightedDrawables.clear();
    return closest;
}

void DrawableHandler::stopStreaming() {
    m_streamDrawable.reset(nullptr);
}

void DrawableHandler::setPen(const QPen& pen, size_t indexOfDrawable) {
    for (auto& el : m_drawables) {
        if (el->index() == indexOfDrawable) {
            el->setPen(pen);
            return;
        }
    }
    assert(false);
}

size_t DrawableHandler::indexOfSelectedDrawable() const {
    if (m_selectedDrawables.empty()) {
        return std::numeric_limits<size_t>::max();
    }
    return m_selectedDrawables.front()->index();
}

const std::vector<Drawable*>& DrawableHandler::selectedDrawables() const {
    return m_selectedDrawables;
}

const std::vector<Drawable*>& DrawableHandler::highlightedDrawables() const {
    return m_highlightedDrawables;
}

const StreamDrawable* DrawableHandler::streamDrawable() const {
    return m_streamDrawable.get();
}

void DrawableHandler::translateAll(const QPointF& translation) {
    for (auto& el : m_drawables) {
        el->translate(translation);
    }
}

void DrawableHandler::translateSelected(const QPointF& translation) {
    for (auto& el : m_selectedDrawables) {
        el->translate(translation);
    }
}
