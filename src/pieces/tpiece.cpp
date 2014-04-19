#include "tpiece.h"

TPiece::TPiece()
{
    _color = 5;
    _origin[0] = 4;
    _origin[1] = 0;
    _orientation = TPIECE_UP;
}

unsigned int TPiece::get_color()
{
    return _color;
}

void TPiece::get_coordinates(unsigned int *coordinates)
{
    switch(_orientation){
    case TPIECE_T:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1];
        coordinates[4] = _origin[0]+2;
        coordinates[5] = _origin[1];
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+1;
        break;
    case TPIECE_LEFT:
        coordinates[0] = _origin[0]+1;
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+2;
        break;
    case TPIECE_RIGHT:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0];
        coordinates[5] = _origin[1]+2;
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+1;
        break;
    case TPIECE_UP:
        coordinates[0] = _origin[0]+1;
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1]+1;
        break;
    }
}

void TPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}
