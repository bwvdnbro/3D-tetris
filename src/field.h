#ifndef FIELD_H
#define FIELD_H

#include "block.h"
#include "pieces/piecefactory.h"
#include <ostream>

class Piece;

class Field
{
private:
    Block _colors[10][20];
    Piece* _piece;
    PieceFactory _factory;

    bool is_valid();
    void save_piece();
    void check_lines();
    void remove_line(unsigned int line);

public:
    Field();
    ~Field();

    void print(std::ostream& stream);
    void move_piece();

    void turn_piece();
    void drop_piece();
    void move_piece_left();
    void move_piece_right();

    void get_colors(unsigned int colors[][10]);
};

#endif // FIELD_H
