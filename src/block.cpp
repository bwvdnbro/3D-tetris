#include "block.h"

Block::Block()
{
    _color = 0.;
}

unsigned int Block::get_color()
{
    return _color;
}

void Block::set_color(unsigned int color)
{
    _color = color;
}
