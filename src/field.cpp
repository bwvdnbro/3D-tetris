#include "field.h"
#include "piece.h"
#include <iostream>
#include <cstdlib>

Field::Field()
{
    _piece = _factory.get_random_piece();
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
            _piece = _factory.get_random_piece();
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
    check_lines();
}

void Field::turn_piece()
{
    if(_piece){
        _piece->turn();
        if(!is_valid()){
            _piece->turn(true);
        }
    }
}

void Field::drop_piece()
{
    if(_piece){
        _piece->move(0,1);
        while(is_valid()){
            _piece->move(0,1);
        }
        _piece->move(0,-1);
        save_piece();
        delete _piece;
        _piece = _factory.get_random_piece();
    }
}

void Field::move_piece_left()
{
    if(_piece){
        _piece->move(-1,0);
        if(!is_valid()){
            _piece->move(1,0);
        }
    }
}

void Field::move_piece_right()
{
    if(_piece){
        _piece->move(1,0);
        if(!is_valid()){
            _piece->move(-1,0);
        }
    }
}

void Field::check_lines()
{
    for(unsigned int line = 19; line--;){
        unsigned int column = 0;
        while(column < 10 && _colors[column][line].get_color()){
            column++;
        }
        if(column == 10){
            remove_line(line);
            // removing a line shifts all lines above one line down
            line++;
        }
    }
}

void Field::remove_line(unsigned int line){
    while(line){
        for(int j = 0; j < 10; j++){
            _colors[j][line].set_color(_colors[j][line-1].get_color());
        }
        line--;
    }

    for(int j = 0; j < 10; j++){
        _colors[j][line].set_color(0);
    }
}
