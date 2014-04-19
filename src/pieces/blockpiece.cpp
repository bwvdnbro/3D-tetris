#include "blockpiece.h"

BlockPiece::BlockPiece()
{
    _color = 1;
    _origin[0] = 4;
    _origin[1] = 0;
}


unsigned int BlockPiece::get_color()
{
    return _color;
}

void BlockPiece::get_coordinates(unsigned int *coordinates)
{
    coordinates[0] = _origin[0];
    coordinates[1] = _origin[1];
    coordinates[2] = _origin[0];
    coordinates[3] = _origin[1]+1;
    coordinates[4] = _origin[0]+1;
    coordinates[5] = _origin[1];
    coordinates[6] = _origin[0]+1;
    coordinates[7] = _origin[1]+1;
}

void BlockPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void BlockPiece::turn(bool turn_back)
{
    // do nothing: a block does not change by turning it
}
