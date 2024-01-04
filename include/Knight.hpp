#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <SFML/Graphics.hpp>

#include "Piece.hpp"

class Knight : public Piece {
public:
    virtual void updateValidMoves(BoardModel boardModel) override;
    
    Knight(int side, Cell *standingOn);
    ~Knight();   

};

void Knight::updateValidMoves(BoardModel boardModel) {

}

Knight::Knight(int side, Cell *standingOn) : Piece(side, standingOn) {
    if (side == -1)
        this->initWithPath(BLACK_KNIGHT_PATH);
    else    
        this->initWithPath(WHITE_KNIGHT_PATH);
    this->setSize(CELL_SIZE);
}

Knight::~Knight() {}

#endif  /* KNIGHT_HPP */