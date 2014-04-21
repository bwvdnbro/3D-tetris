#ifndef FIELD3D_H
#define FIELD3D_H

#include "block.h"

class Piece3D;

class Field3D
{
private:
    Block _colors[10][10][20];
    Piece3D* _piece;
    //PieceFactory _factory;

    bool is_valid();
    void save_piece();
    void check_lines();
    void remove_line(unsigned int line);

public:
    Field3D();
    ~Field3D();

    void move_piece();

    void turn_piece_x();
    void turn_piece_y();
    void drop_piece();
    void move_piece_left();
    void move_piece_right();
    void move_piece_front();
    void move_piece_back();

    void get_colors(unsigned int colors[][10][10]);
};

#endif // FIELD3D_H
