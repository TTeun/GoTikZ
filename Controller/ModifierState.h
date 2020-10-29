//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_MODIFIERSTATE_H
#define GOTIKZ_MODIFIERSTATE_H

namespace controller {
    class ModifierState {

      public:
        ModifierState() = default;

        bool shiftPressed() const;
        bool controlPressed() const;
        void setShiftPressed(bool shiftPressed);
        void setControlPress(bool controlPressed);

      private:
        bool m_shiftPressed;
        bool m_controlPressed;
    };
} // namespace controller

#endif // GOTIKZ_MODIFIERSTATE_H
