#include "spiece.h"

SPiece::SPiece()
{
    _color = 4;
    _origin[0] = 4;
    _origin[1] = 0;
    _orientation = SPIECE_LIGHTNING;
}

unsigned int SPiece::get_color()
{
    return _color;
}

void SPiece::get_coordinates(unsigned int *coordinates)
{
    if(_orientation == SPIECE_S){
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1]+1;
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1];
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1];
    } else {
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+2;
    }
}

void SPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void SPiece::turn(bool turn_back)
{
    if(_orientation == SPIECE_S){
        _orientation = SPIECE_LIGHTNING;
    } else {
        _orientation = SPIECE_S;
    }
}
