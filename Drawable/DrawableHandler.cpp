//
// Created by pc on 27-10-20.
//

#include "DrawableHandler.h"

#include "Drawable/ControlPoint/ControlPointFactory.h"

void DrawableHandler::addDrawable(Drawable* drawable) {
    drawable->setVisible(true);
    m_drawables.push_back(std::unique_ptr<Drawable>(drawable));
    ControlPointFactory fac(drawable);
    for (size_t i = 0; i != fac.numberOfControlPoints(); ++i) {
        m_controlPoints.push_back(std::unique_ptr<ControlPoint>(fac.controlPoint(i)));
    }
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
    auto it = m_controlPoints.begin();
    while (it != m_controlPoints.end()) {
        assert((*it)->drawable() != nullptr);
        if ((*it)->drawable() == returnPointer) {
            it = m_controlPoints.erase(it);
        } else {
            ++it;
        }
    }
    returnPointer->setVisible(false);
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
    m_highlightedDrawable = nullptr;
}

void DrawableHandler::highlightClosest(const QPointF& point) {
    m_highlightedDrawable = nullptr;
    for (auto& el : m_controlPoints) {
        el->setHighlighted(false);
    }
    auto* closestDrawable = getClosest(point);
    if (closestDrawable != nullptr) {
        ControlPoint* closestControlPoint = getClosestControlPoint(point, std::numeric_limits<size_t>::max());
        if (closestControlPoint->dist(point) < 2 * closestDrawable->dist(point)) {
            closestControlPoint->setHighlighted(true);
        } else {
            if (std::find(m_selectedDrawables.begin(), m_selectedDrawables.end(), closestDrawable) ==
                m_selectedDrawables.end()) {
                m_highlightedDrawable = closestDrawable;
            } else {
                m_highlightedDrawable = nullptr;
            }
        }
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

Drawable* DrawableHandler::selectNew(const QPointF& point) {
    m_highlightedDrawable = nullptr;
    auto* closest         = getClosest(point);
    if (closest == nullptr) {
        updateControlPoints();
        return nullptr;
    } else {
        m_selectedDrawables = {closest};
        updateControlPoints();
        return closest;
    }
}

Drawable* DrawableHandler::addToSelected(const QPointF& point) {
    m_highlightedDrawable = nullptr;
    auto* closest         = getClosest(point);
    if (closest == nullptr) {
        updateControlPoints();
        return nullptr;
    } else {
        auto it = std::find(m_selectedDrawables.begin(), m_selectedDrawables.end(), closest);
        if (it == m_selectedDrawables.end()) {
            m_selectedDrawables.push_back(closest);
            updateControlPoints();
            return closest;
        } else {
            m_selectedDrawables.erase(it);
            updateControlPoints();
            return nullptr;
        }
    }
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

std::vector<size_t> DrawableHandler::indicesOfSelectedDrawable() const {
    std::vector<size_t> indices;
    for (auto& el : m_selectedDrawables) {
        indices.push_back(el->index());
    }
    return indices;
}

const std::vector<Drawable*>& DrawableHandler::selectedDrawables() const {
    return m_selectedDrawables;
}

const Drawable* DrawableHandler::highlightedDrawable() const {
    return m_highlightedDrawable;
}

const StreamDrawable* DrawableHandler::streamDrawable() const {
    return m_streamDrawable.get();
}

void DrawableHandler::translateSelected(const QPointF& translation) {
    for (auto& el : m_selectedDrawables) {
        el->translate(translation);
    }
}

void DrawableHandler::translate(size_t indexOfPrimitive, const QPointF& translation) {
    for (auto& el : m_drawables) {
        if (el->index() == indexOfPrimitive) {
            el->translate(translation);
            return;
        }
    }
    assert(false);
}

const std::vector<std::unique_ptr<ControlPoint>>& DrawableHandler::controlPoints() const {
    return m_controlPoints;
}

void DrawableHandler::updateControlPoints() {
    for (auto& el : m_controlPoints) {
        el->update();
    }
}

ControlPoint* DrawableHandler::getClosestControlPoint(const QPointF& mousePosition, size_t maximumDistance) const {
    if (m_controlPoints.empty()) {
        return nullptr;
    }
    ControlPoint* closest = m_controlPoints.front().get();
    for (const auto& el : m_controlPoints) {
        if (el->dist(mousePosition) < closest->dist(mousePosition)) {
            closest = el.get();
        }
    }
    if (closest->dist(mousePosition) < maximumDistance) {
        return closest;
    } else {
        return nullptr;
    }
}
