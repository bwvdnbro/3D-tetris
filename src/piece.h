#ifndef PIECE_H
#define PIECE_H

class Piece{
public:
    virtual void get_coordinates(unsigned int* coordinates)=0;
    virtual unsigned int get_color()=0;
};

#endif // PIECE_H
