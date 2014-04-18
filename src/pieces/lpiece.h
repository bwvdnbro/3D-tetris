#ifndef LPIECE_H
#define LPIECE_H

#include "../piece.h"

enum LPieceOrientation{
    LPIECE_L,
    LPIECE_DOWN,
    LPIECE_SHORT_LEFT,
    LPIECE_LONG_LEFT
};

class LPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    LPieceOrientation _orientation;

public:
    LPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
};

#endif // LPIECE_H
