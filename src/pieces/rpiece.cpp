#include "rpiece.h"

RPiece::RPiece()
{
    _color = 6;
    _origin[0] = 4;
    _origin[1] = 0;
    _orientation = RPIECE_DOWN;
}

unsigned int RPiece::get_color()
{
    return _color;
}

void RPiece::get_coordinates(unsigned int *coordinates)
{
    switch(_orientation){
    case RPIECE_SHORT_LEFT:
        coordinates[0] = _origin[0]+1;
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+2;
        coordinates[6] = _origin[0];
        coordinates[7] = _origin[1]+2;
        break;
    case RPIECE_LONG_RIGHT:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0];
        coordinates[3] = _origin[1]+1;
        coordinates[4] = _origin[0]+1;
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1]+1;
        break;
    case RPIECE_GAMMA:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1];
        coordinates[4] = _origin[0];
        coordinates[5] = _origin[1]+1;
        coordinates[6] = _origin[0];
        coordinates[7] = _origin[1]+2;
        break;
    case RPIECE_DOWN:
        coordinates[0] = _origin[0];
        coordinates[1] = _origin[1];
        coordinates[2] = _origin[0]+1;
        coordinates[3] = _origin[1];
        coordinates[4] = _origin[0]+2;
        coordinates[5] = _origin[1];
        coordinates[6] = _origin[0]+2;
        coordinates[7] = _origin[1]+1;
        break;
    }
}

void RPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void RPiece::turn(bool turn_back)
{
    if(turn_back){
        turn(false);
        turn(false);
    }

    switch(_orientation){
    case RPIECE_DOWN:
        _orientation = RPIECE_GAMMA;
        break;
    case RPIECE_GAMMA:
        _orientation = RPIECE_LONG_RIGHT;
        break;
    case RPIECE_LONG_RIGHT:
        _orientation = RPIECE_SHORT_LEFT;
        break;
    case RPIECE_SHORT_LEFT:
        _orientation = RPIECE_DOWN;
        break;
    }
}
