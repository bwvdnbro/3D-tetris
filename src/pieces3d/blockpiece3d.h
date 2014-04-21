#ifndef BLOCKPIECE3D_H
#define BLOCKPIECE3D_H

#include "../piece3d.h"

class BlockPiece3D : public Piece3D
{
private:
    unsigned int _color;
    unsigned int _origin[3];

public:
    BlockPiece3D();

    void get_coordinates(unsigned int* coordinates);
    unsigned int get_color();
    void move(int x, int y, int z);
    void turn_x(bool turn_back = false);
    void turn_y(bool turn_back = false);
};

#endif // BLOCKPIECE3D_H
