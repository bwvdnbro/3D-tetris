#include "lpiece.h"

LPiece::LPiece()
{
    _color = 7;
    _origin[0] = 3;
    _origin[1] = 0;
    _orientation = LPIECE_LONG_LEFT;
}

unsigned int LPiece::get_color()
{
    return _color;
}

void LPiece::get_coordinates(unsigned int *coordinates)
{
    switch(_orientation){
    case LPIECE_L:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0];
        coordinates[5] = _origin[1]+2;
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+2;
        break;
    case LPIECE_DOWN:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1];
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1];
        break;
    case LPIECE_SHORT_LEFT:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1];
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+1;
        coordinates[7] = _origin[1]+2;
        break;
    case LPIECE_LONG_LEFT:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1]+1;
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+2;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1];
        break;
    }
}

void LPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void LPiece::turn(bool turn_back)
{
    if(turn_back){
        turn(false);
        turn(false);
    }

    switch(_orientation){
    case LPIECE_L:
        _orientation = LPIECE_LONG_LEFT;
        break;
    case LPIECE_LONG_LEFT:
        _orientation = LPIECE_SHORT_LEFT;
        break;
    case LPIECE_SHORT_LEFT:
        _orientation = LPIECE_DOWN;
        break;
    case LPIECE_DOWN:
        _orientation = LPIECE_L;
        break;
    }
}
