#include "zpiece.h"

ZPiece::ZPiece()
{
    _color = 3;
    _origin[0] = 4;
    _origin[1] = 0;
    _orientation = ZPIECE_LIGHTNING;
}

unsigned int ZPiece::get_color()
{
    return _color;
}

void ZPiece::get_coordinates(unsigned int *coordinates)
{
    if(_orientation == ZPIECE_Z){
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1];
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1]+1;
    } else {
        coordinates[0] = _origin[0]+1;
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0];
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0];
        coordinates[7] = _origin[1]+2;
    }
}

void ZPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void ZPiece::turn(bool turn_back)
{
    if(_orientation == ZPIECE_Z){
        _orientation = ZPIECE_LIGHTNING;
    } else {
        _orientation = ZPIECE_Z;
    }
}
