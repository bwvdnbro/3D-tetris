#include "piecefactory.h"
#include "blockpiece.h"
#include "longpiece.h"
#include "lpiece.h"
#include "rpiece.h"
#include "spiece.h"
#include "tpiece.h"
#include "zpiece.h"
#include <cstdlib>
#include <ctime>

PieceFactory::PieceFactory()
{
    // set the seed for the random number generator
    srand(time(0));
}

Piece* PieceFactory::get_random_piece()
{
    switch(rand()%7){
    case BLOCKPIECE:
        return new BlockPiece();
    case LONGPIECE:
        return new LongPiece();
    case ZPIECE:
        return new ZPiece();
    case SPIECE:
        return new SPiece();
    case TPIECE:
        return new TPiece();
    case RPIECE:
        return new RPiece();
    case LPIECE:
        return new LPiece();
    }
}
