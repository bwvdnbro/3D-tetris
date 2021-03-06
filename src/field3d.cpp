#include "field3d.h"
#include "piece3d.h"
#include "pieces3d/blockpiece3d.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Field3D::Field3D()
{
    _piece = new BlockPiece3D();
}

Field3D::~Field3D()
{
    delete _piece;
}

void Field3D::move_piece()
{
    if(_piece){
        _piece->move(0,0,1);
        if(!is_valid()){
            _piece->move(0,0,-1);
            save_piece();
            delete _piece;
            _piece = new BlockPiece3D();
        }
    }
}

void Field3D::turn_piece_x()
{
    if(_piece){
        _piece->turn_x();
        if(!is_valid()){
            _piece->turn_x(true);
        }
    }
}

void Field3D::turn_piece_y()
{
    if(_piece){
        _piece->turn_y();
        if(!is_valid()){
            _piece->turn_y(true);
        }
    }
}

void Field3D::turn_piece_z()
{
    if(_piece){
        _piece->turn_z();
        if(!is_valid()){
            _piece->turn_z(true);
        }
    }
}

void Field3D::drop_piece()
{
    if(_piece){
        _piece->move(0,0,1);
        while(is_valid()){
            _piece->move(0,0,1);
        }
        _piece->move(0,0,-1);
        save_piece();
        delete _piece;
        _piece = new BlockPiece3D();
    }
}

void Field3D::move_piece_left()
{
    if(_piece){
        _piece->move(0,-1,0);
        if(!is_valid()){
            _piece->move(0,1,0);
        }
    }
}

void Field3D::move_piece_right()
{
    if(_piece){
        _piece->move(0,1,0);
        if(!is_valid()){
            _piece->move(0,-1,0);
        }
    }
}

void Field3D::move_piece_front()
{
    if(_piece){
        _piece->move(1,0,0);
        if(!is_valid()){
            _piece->move(-1,0,0);
        }
    }
}

void Field3D::move_piece_back()
{
    if(_piece){
        _piece->move(-1,0,0);
        if(!is_valid()){
            _piece->move(1,0,0);
        }
    }
}

void Field3D::get_colors(unsigned int colors[][10][10])
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                colors[i][j][k] = _colors[k][j][i].get_color();
            }
        }
    }

    if(_piece){
        unsigned int coordinates[12];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            colors[coordinates[3*i+2]][coordinates[3*i+1]][coordinates[3*i]] = _piece->get_color();
        }
    }
}

bool Field3D::is_valid()
{
    if(_piece){
        unsigned int coordinates[12];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            if(coordinates[3*i] < 0 || coordinates[3*i] > 9){
                return false;
            }
            if(coordinates[3*i+1] < 0 || coordinates[3*i+1] > 9){
                return false;
            }
            if(coordinates[3*i+2] < 0 || coordinates[3*i+2] > 19){
                return false;
            }
            if(_colors[coordinates[3*i]][coordinates[3*i+1]][coordinates[3*i+2]].get_color()){
                return false;
            }
        }
    }
    return true;
}

void Field3D::save_piece()
{
    if(_piece){
        unsigned int coordinates[12];
        _piece->get_coordinates(coordinates);
        for(int i = 0; i < 4; i++){
            _colors[coordinates[3*i]][coordinates[3*i+1]][coordinates[3*i+2]].set_color(_piece->get_color());
        }
    }
    check_lines();
}

void Field3D::check_lines()
{
    for(unsigned int z = 20; z--;){
        unsigned int x = 0;
        unsigned int y = 0;
        while(x < 10 && y == x*10 && _colors[x][y-x*10][z].get_color()){
            y++;
            while(y < (x+1)*10 && _colors[x][y-x*10][z].get_color()){
                y++;
            }
            x++;
        }
        if(y == 100){
            remove_line(z);
            // removing a line shifts all lines above one line down
            z++;
        }
    }
}

void Field3D::remove_line(unsigned int line)
{
    // do something. Should be remove_plane instead...
    while(line){
        for(int j = 0; j < 10; j++){
            for(int i = 0; i < 10; i++){
                _colors[j][i][line].set_color(_colors[j][i][line-1].get_color());
            }
        }
        line--;
    }

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            _colors[j][i][line].set_color(0);
        }
    }
}
