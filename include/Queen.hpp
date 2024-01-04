#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>

#include "Piece.hpp"

class Queen : public Piece {
public:
    virtual void updateValidMoves(BoardModel boardModel) override;
    
    Queen(int side, Cell *standingOn);
    ~Queen();   

};

void Queen::updateValidMoves(BoardModel boardModel) {
    
}

Queen::Queen(int side, Cell *standingOn) : Piece(side, standingOn) {
    if (side == -1)
        this->initWithPath(BLACK_QUEEN_PATH);
    else    
        this->initWithPath(WHITE_QUEEN_PATH);
    this->setSize(CELL_SIZE);
}

Queen::~Queen() {}

#endif  /* QUEEN_HPP */