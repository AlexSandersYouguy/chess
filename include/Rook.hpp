#ifndef ROOK_HPP
#define ROOK_HPP

#include <SFML/Graphics.hpp>

#include "Piece.hpp"

class Rook : public Piece {
private:
    bool wasFirstMove = false;
public:
    virtual void updateValidMoves(BoardModel boardModel) override;
    
    Rook(int side, Cell *standingOn);
    ~Rook();
};

void Rook::updateValidMoves(BoardModel boardModel) {
    m_validMoves.clear();
    Movement potentialMove;
    potentialMove.fromCellCoordinates = this->getCoordinates();
    // vertical moves
    for (int i = this->getCoordinates().x, j = this->getCoordinates().y; i < FIELD_SIDE; i++) {
        if (boardModel.getCellModel(i, j).m_side == m_side) 
            break;
        else if (boardModel.getCellModel(i, j).m_side == -m_side) {
            potentialMove.type = MovementType::CAPTURE;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
            break;
        }
        else {
            potentialMove.type = MovementType::DEFAULT;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
        }
    }
    for (int i = this->getCoordinates().x, j = this->getCoordinates().y; i >= 0; i--) {
        if (boardModel.getCellModel(i, j).m_side == m_side) 
            break;
        else if (boardModel.getCellModel(i, j).m_side == -m_side) {
            potentialMove.type = MovementType::CAPTURE;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
            break;
        }
        else {
            potentialMove.type = MovementType::DEFAULT;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
        }
    }
    // horizontal moves
    for (int i = this->getCoordinates().x, j = this->getCoordinates().y; j < FIELD_SIDE; j++) {
        if (boardModel.getCellModel(i, j).m_side == m_side) 
            break;
        else if (boardModel.getCellModel(i, j).m_side == -m_side) {
            potentialMove.type = MovementType::CAPTURE;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
            break;
        }
        else {
            potentialMove.type = MovementType::DEFAULT;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
        }
    }
    for (int i = this->getCoordinates().x, j = this->getCoordinates().y; j >= 0; j--) {
        if (boardModel.getCellModel(i, j).m_side == m_side) 
            break;
        else if (boardModel.getCellModel(i, j).m_side == -m_side) {
            potentialMove.type = MovementType::CAPTURE;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
            break;
        }
        else {
            potentialMove.type = MovementType::DEFAULT;
            potentialMove.toCellCoordinates = sf::Vector2i(i, j);
            m_validMoves.push_back(potentialMove);
        }
    }
}

Rook::Rook(int side, Cell *standingOn) : Piece(side, standingOn) {
    if (side == -1)
        this->initWithPath(BLACK_ROOK_PATH);
    else    
        this->initWithPath(WHITE_ROOK_PATH);
    this->setSize(CELL_SIZE);
}

Rook::~Rook() {}

#endif  /* ROOK_HPP */