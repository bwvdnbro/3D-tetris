#ifndef BLOCKPIECE_H
#define BLOCKPIECE_H

#include "../piece.h"

class BlockPiece : public Piece
{
private:
    unsigned int _color;

    // origin of the piece: the left upper corner
    unsigned int _origin[2];

public:
    BlockPiece();

    void get_coordinates(unsigned int *coordinates);
    unsigned int get_color();
    void move(int x, int y);
};

#endif // BLOCKPIECE_H
