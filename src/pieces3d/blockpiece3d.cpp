#include "blockpiece3d.h"

BlockPiece3D::BlockPiece3D()
{
    _color = 1;
    _origin[0] = 0;
    _origin[1] = 0;
    _origin[2] = 0;
}

void BlockPiece3D::get_coordinates(unsigned int *coordinates)
{
    coordinates[0] = _origin[0];
    coordinates[1] = _origin[1];
    coordinates[2] = _origin[2];

    coordinates[3] = _origin[0]+1;
    coordinates[4] = _origin[1];
    coordinates[5] = _origin[2];

    coordinates[6] = _origin[0];
    coordinates[7] = _origin[1]+1;
    coordinates[8] = _origin[2];

    coordinates[9] = _origin[0]+1;
    coordinates[10] = _origin[1]+1;
    coordinates[11] = _origin[2];
}

unsigned int BlockPiece3D::get_color()
{
    return _color;
}

void BlockPiece3D::move(int x, int y, int z)
{
    _origin[0] += x;
    _origin[1] += y;
    _origin[2] += z;
}

void BlockPiece3D::turn_x(bool turn_back)
{
    // do nothing
}

void BlockPiece3D::turn_y(bool turn_back)
{
    // do nothing
}

void BlockPiece3D::turn_z(bool turn_back)
{
    // do nothing
}
