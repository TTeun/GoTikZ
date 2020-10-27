//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MODEL_H
#define GOTIKZ_MODEL_H

#include "Drawable/DrawableHandler.h"

class Model {

  public:
    Model() = default;

    const DrawableHandler& drawableHandler() const {
        return m_drawableHandler;
    }

  private:
    DrawableHandler m_drawableHandler;
};

#endif // GOTIKZ_MODEL_H
