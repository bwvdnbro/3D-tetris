#ifndef LONGPIECE_H
#define LONGPIECE_H

#include "../piece.h"

enum LongPieceOrientation{
    LONGPIECE_FLAT,
    LONGPIECE_STRAIGHT
};

class LongPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    LongPieceOrientation _orientation;

public:
    LongPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
    void move(int x, int y);
    void turn(bool turn_back);
};

#endif // LONGPIECE_H
