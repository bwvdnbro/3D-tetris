#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

enum PieceType{
    BLOCKPIECE,
    LONGPIECE,
    ZPIECE,
    SPIECE,
    TPIECE,
    RPIECE,
    LPIECE
};

class Piece;

class PieceFactory
{
public:
    PieceFactory();

    Piece* get_random_piece();
};

#endif // PIECEFACTORY_H
