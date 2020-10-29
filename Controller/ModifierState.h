//
// Created by pc on 29-10-20.
//

#ifndef GOTIKZ_MODIFIERSTATE_H
#define GOTIKZ_MODIFIERSTATE_H

namespace Controller {
    class ModifierState {

        friend class ActionHandler;

      public:
        ModifierState() = default;

        bool shiftPressed() const ;

        bool controlPressed() const;

      private:
        bool m_shiftPressed;
        bool m_controlPressed;
    };
} // namespace Controller

#endif // GOTIKZ_MODIFIERSTATE_H
