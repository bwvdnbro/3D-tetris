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

    bool is_valid();
    void save_piece();

public:
    Field();
    ~Field();

    void print(std::ostream& stream);
    void move_piece();
    void get_colors(unsigned int colors[][10]);
};

#endif // FIELD_H
