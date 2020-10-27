//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_CONTROLLER_H
#define GOTIKZ_CONTROLLER_H

#include "Actions/ActionHandler.h"
#include "Widgets/MainWidget.h"

class Controller {

  private:
    ActionHandler m_actionHandler;
    MainWidget    m_view;
};

#endif // GOTIKZ_CONTROLLER_H
