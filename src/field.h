#ifndef FIELD_H
#define FIELD_H

#include "block.h"
#include <ostream>

class Piece;

class Field
{
private:
    Block _colors[10][20];
    Piece* _piece;

public:
    Field();
    ~Field();

    void print(std::ostream& stream);
};

#endif // FIELD_H
