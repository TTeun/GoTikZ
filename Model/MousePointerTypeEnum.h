//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_MOUSEPOINTERTYPEENUM_H
#define GOTIKZ_MOUSEPOINTERTYPEENUM_H

class QString;

namespace Model {
    enum class MOUSE_POINTER_TYPE { LINE, POINT, CIRCLE, POLY_LINE, SELECT };
}

Model::MOUSE_POINTER_TYPE mousePointerTypeFromString(const QString& str);

#endif // GOTIKZ_MOUSEPOINTERTYPEENUM_H
