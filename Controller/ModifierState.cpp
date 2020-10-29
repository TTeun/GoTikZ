//
// Created by pc on 29-10-20.
//

#include "ModifierState.h"

bool Controller::ModifierState::shiftPressed() const {
    return m_shiftPressed;
}

bool Controller::ModifierState::controlPressed() const {
    return m_controlPressed;
}
