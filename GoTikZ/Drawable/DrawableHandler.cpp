//
// Created by pc on 27-10-20.
//

#include "DrawableHandler.h"

#include <QPainter>

void DrawableHandler::draw(QPainter* painter) const {
    for (const auto& el : m_drawables) {
        el->draw(painter, Drawable::DRAW_FLAGS::NONE);
    }

    for (const auto& el : m_highlightedDrawables) {
        el->draw(painter, Drawable::DRAW_FLAGS::HIGHLIGHTED);
    }

    for (const auto& el : m_selectedDrawables) {
        el->draw(painter, Drawable::DRAW_FLAGS::SELECTED);
    }

    if (m_streamDrawable) {
        m_streamDrawable->draw(painter, Drawable::DRAW_FLAGS::NONE);
    }
}

void DrawableHandler::addDrawable(Drawable* drawable) {
    m_drawables.push_back(std::unique_ptr<Drawable>(drawable));
}

void DrawableHandler::addStreamDrawable(StreamDrawable* streamDrawable) {
    assert(m_streamDrawable == nullptr);
    m_streamDrawable.reset(streamDrawable);
}

bool DrawableHandler::isStreaming() {
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

const std::vector<std::unique_ptr<Drawable>>& DrawableHandler::drawables() {
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
    std::pair<double, QPointF> snapData{std::numeric_limits<double>::max(), mousePoint};
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

void DrawableHandler::clearSelected() {
    m_selectedDrawables.clear();
    m_highlightedDrawables.clear();
}

void DrawableHandler::highlightClosest(const QPointF& point) {
    auto* closest = getClosest(point);
    if (closest == nullptr) {
        return;
    }
    m_highlightedDrawables = {closest};
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
