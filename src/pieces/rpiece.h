#ifndef RPIECE_H
#define RPIECE_H

#include "../piece.h"

enum RPieceOrientation{
    RPIECE_SHORT_LEFT,
    RPIECE_LONG_RIGHT,
    RPIECE_GAMMA,
    RPIECE_DOWN
};

class RPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    RPieceOrientation _orientation;

public:
    RPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
    void move(int x, int y);
    void turn(bool turn_back);
};

#endif // RPIECE_H
