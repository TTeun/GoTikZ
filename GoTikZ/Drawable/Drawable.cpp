//
// Created by pc on 15-10-20.
//

#include "Drawable.h"

#include <QPainter>
#include <utility>

Drawable::Drawable(QPen pen) : m_pen(std::move(pen)) {}

void Drawable::draw(QPainter *painter) { painter->setPen(m_pen); }
