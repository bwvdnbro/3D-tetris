#ifndef ZPIECE_H
#define ZPIECE_H

#include "../piece.h"

enum ZPieceOrientation{
    ZPIECE_Z,
    ZPIECE_LIGHTNING
};

class ZPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    ZPieceOrientation _orientation;

public:
    ZPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
};

#endif // ZPIECE_H
