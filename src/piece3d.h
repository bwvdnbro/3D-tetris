#ifndef PIECE3D_H
#define PIECE3D_H

class Piece3D{
public:
    virtual void get_coordinates(unsigned int* coordinates)=0;
    virtual unsigned int get_color()=0;
    virtual void move(int x, int y, int z)=0;
    virtual void turn_x(bool turn_back = false)=0;
    virtual void turn_y(bool turn_back = false)=0;
    virtual void turn_z(bool turn_back = false)=0;
};

#endif // PIECE3D_H
