#ifndef BLOCK_H
#define BLOCK_H

class Block
{
private:
    unsigned int _color;

public:
    Block();

    unsigned int get_color();
    void set_color(unsigned int color);
};

#endif // BLOCK_H
