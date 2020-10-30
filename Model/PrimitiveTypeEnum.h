//
// Created by pc on 27-10-20.
//

#ifndef GOTIKZ_PRIMITIVETYPEENUM_H
#define GOTIKZ_PRIMITIVETYPEENUM_H

class QString;

enum class PRIMITIVE_TYPE { LINE, POINT, CIRCLE, POLY_LINE, STREAM };

PRIMITIVE_TYPE primitiveTypeFromString(const QString& str);

#endif // GOTIKZ_PRIMITIVETYPEENUM_H
