#ifndef BLOCKPIECE_H
#define BLOCKPIECE_H

#include "../piece.h"

class BlockPiece : public Piece
{
private:
    unsigned int _color;

public:
    BlockPiece();
};

#endif // BLOCKPIECE_H
