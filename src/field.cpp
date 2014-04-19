#include "field.h"
#include "piece.h"
#include "pieces/lpiece.h"
#include "pieces/longpiece.h"
#include <iostream>
#include <cstdlib>

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

void Field::move_piece()
{
    if(_piece){
        _piece->move(0,1);
        if(!is_valid()){
            _piece->move(0,-1);
            save_piece();
            delete _piece;
            _piece = new LongPiece();
        }
    }
}

void Field::get_colors(unsigned int colors[][10]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            colors[i][j] = _colors[j][i].get_color();
        }
    }

    if(_piece){
        unsigned int coordinates[8];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            colors[coordinates[2*i+1]][coordinates[2*i]] = _piece->get_color();
        }
    }
}

bool Field::is_valid()
{
    if(_piece){
        unsigned int coordinates[8];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            if(coordinates[2*i] < 0 || coordinates[2*i] > 9){
                return false;
            }
            if(coordinates[2*i+1] < 0 || coordinates[2*i+1] > 19){
                return false;
            }
            if(_colors[coordinates[2*i]][coordinates[2*i+1]].get_color()){
                return false;
            }
        }
    }
    return true;
}

void Field::save_piece()
{
    if(_piece){
        unsigned int coordinates[8];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            _colors[coordinates[2*i]][coordinates[2*i+1]].set_color(_piece->get_color());
        }
    }
}
