#ifndef FIELD_H
#define FIELD_H

#include "block.h"

class Piece;

class Field
{
private:
    Block _colors[10][20];
    Piece* _piece;

public:
    Field();
};

#endif // FIELD_H
