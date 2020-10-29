//
// Created by pc on 29-10-20.
//

#include "ModifierState.h"

bool controller::ModifierState::shiftPressed() const {
    return m_shiftPressed;
}

bool controller::ModifierState::controlPressed() const {
    return m_controlPressed;
}
