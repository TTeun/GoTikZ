//
// Created by pc on 15-10-20.
//

#include "PolyLine_Stream.h"

#include "PolyLine.h"
#include "QPainter"

#include <Math/Math.h>

PolyLine_Stream::PolyLine_Stream(const QPointF& point, const QPen& pen)
    : StreamDrawable(pen)
{
    m_points.push_back(point);
    m_points.push_back(point);
}

void PolyLine_Stream::draw(QPainter* painter)
{
    assert(m_points.size() > 1);
    Drawable::draw(painter);
    for (long i = 1; i != m_points.size(); ++i)
    {
        painter->drawLine(m_points[i - 1], m_points[i]);
    }
}

void PolyLine_Stream::stream(const QPointF& point) { m_points.back() = point; }

bool PolyLine_Stream::addPoint(const QPointF& point, bool forceEnd)
{
    m_points.back() = point;
    m_points.push_back(point);
    return forceEnd;
}

Drawable* PolyLine_Stream::drawable() { return new PolyLine(*this); }

std::pair<double, QPointF> PolyLine_Stream::snap(QPointF point)
{
    auto snapData =
        std::pair<double, QPointF>(std::numeric_limits<double>::max(), point);
    for (long i = 0; i != m_points.size() - 2; ++i)
    {
        const auto& el = m_points[i];
        if (Math::magnitude(point - el) < snapData.first)
        {
            snapData = {Math::magnitude(point - el), el};
        }
    }
    return snapData;
}
