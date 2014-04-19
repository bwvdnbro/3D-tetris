#ifndef SPIECE_H
#define SPIECE_H

#include "../piece.h"

enum SPieceOrientation{
    SPIECE_S,
    SPIECE_LIGHTNING
};

class SPiece : public Piece
{
private:
    unsigned int _color;
    unsigned int _origin[2];
    SPieceOrientation _orientation;

public:
    SPiece();

    unsigned int get_color();
    void get_coordinates(unsigned int *coordinates);
    void move(int x, int y);
};

#endif // SPIECE_H
