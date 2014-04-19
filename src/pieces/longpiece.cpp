#include "longpiece.h"

LongPiece::LongPiece()
{
    _color = 2;
    _origin[0] = 3;
    _origin[1] = 0;
    _orientation = LONGPIECE_FLAT;
}

unsigned int LongPiece::get_color()
{
    return _color;
}

void LongPiece::get_coordinates(unsigned int *coordinates){
    if(_orientation == LONGPIECE_FLAT){
        for(int i = 0; i < 4; i++){
            coordinates[2*i] = _origin[0]+i;
            coordinates[2*i+1] = _origin[1];
        }
    } else {
        for(int i = 0; i < 4; i++){
            coordinates[2*i] = _origin[0];
            coordinates[2*i+1] = _origin[1]+i;
        }
    }
}

void LongPiece::move(int x, int y)
{
    _origin[0] += x;
    _origin[1] += y;
}

void LongPiece::turn(bool turn_back)
{
    if(_orientation == LONGPIECE_FLAT){
        _orientation = LONGPIECE_STRAIGHT;
    } else {
        _orientation = LONGPIECE_FLAT;
    }
}
