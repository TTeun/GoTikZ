//
// Created by pc on 27-10-20.
//

#include "DrawableHandler.h"

void DrawableHandler::draw(QPainter* painter) {
    for (const auto& el : m_drawables) {
        el->draw(painter);
    }
    if (m_streamDrawable) {
        m_streamDrawable->draw(painter);
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

QPointF DrawableHandler::snap(const QPointF& mousePoint) {
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
