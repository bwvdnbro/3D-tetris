#include "field.h"
#include "piece.h"
#include "pieces/lpiece.h"
#include <iostream>

Field::Field()
{
    _piece = new LPiece();
}

Field::~Field(){
    delete _piece;
}

void Field::print(std::ostream &stream)
{
    unsigned int field[20][10];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            field[i][j] = _colors[j][i].get_color();
        }
    }

    if(_piece){
        unsigned int coordinates[8];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            field[coordinates[2*i+1]][coordinates[2*i]] = _piece->get_color();
        }
    }

    for(int i = 0; i < 20; i++){
        stream << "|";
        for(int j = 0; j < 10; j++){
            stream << field[i][j];
        }
        stream << "|\n";
    }
}
