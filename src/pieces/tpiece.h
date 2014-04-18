#ifndef TPIECE_H
#define TPIECE_H

#include "../piece.h"

enum TPieceOrientation{
    TPIECE_T,
    TPIECE_LEFT,
    TPIECE_RIGHT,
    TPIECE_UP
};

class TPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    TPieceOrientation _orientation;

public:
    TPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
};

#endif // TPIECE_H
