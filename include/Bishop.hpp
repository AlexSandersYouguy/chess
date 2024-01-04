#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <SFML/Graphics.hpp>

#include "Piece.hpp"

class Bishop : public Piece {
public:
    virtual void updateValidMoves(BoardModel boardModel) override;
    Bishop(int side, Cell *standingOn);
    ~Bishop();   
    
};

void Bishop::updateValidMoves(BoardModel boardModel) {
    m_validMoves.clear();
    Movement potentialMove;
    potentialMove.fromCellCoordinates = this->getCoordinates();
    sf::Vector2i difference[4] = {
        sf::Vector2i(1, 1),     // forward by main diagonal
        sf::Vector2i(-1, 1),    // backward by side diagonal
        sf::Vector2i(1, -1),    // forward by side diagonal
        sf::Vector2i(-1, -1),   // backward by main diagonal
    };
    for (sf::Vector2i shift : difference) {
        for (sf::Vector2i newCoordinates = this->getCoordinates(); 
        (newCoordinates.x < FIELD_SIDE && newCoordinates.x >= 0) && (newCoordinates.y < FIELD_SIDE && newCoordinates.y >= 0); 
        newCoordinates += shift) {
            if (boardModel.getCellModel(newCoordinates).m_side == m_side) 
                break;
            else if (boardModel.getCellModel(newCoordinates).m_side == -m_side) {
                BoardModel potentialBoardSituation(boardModel);
            }
        }
    }




    // // by main diagonal
    // for (int i = m_cell->getCoordinates().x, j = m_cell->getCoordinates().y; i < FIELD_SIDE && j < FIELD_SIDE; i++, j++) {
    //     if (boardModel.getCellModel(i, j).m_side == m_side) 
    //         break;
    //     else if (boardModel.getCellModel(i, j).m_side == -m_side) {
    //         potentialMove.type = MovementType::CAPTURE;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //         break;
    //     }
    //     else {
    //         potentialMove.type = MovementType::DEFAULT;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //     }
    // }
    // for (int i = m_cell->getCoordinates().x, j = m_cell->getCoordinates().y; i >= 0 && j >= 0; i--, j--) {
    //     if (boardModel.getCellModel(i, j).m_side == m_side) 
    //         break;
    //     else if (boardModel.getCellModel(i, j).m_side == -m_side) {
    //         potentialMove.type = MovementType::CAPTURE;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //         break;
    //     }
    //     else {
    //         potentialMove.type = MovementType::DEFAULT;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //     }
    // }
    // // by side diagonal
    // for (int i = m_cell->getCoordinates().x, j = m_cell->getCoordinates().y; i >= 0 && j < FIELD_SIDE; i--, j++) {
    //     if (boardModel.getCellModel(i, j).m_side == m_side) 
    //         break;
    //     else if (boardModel.getCellModel(i, j).m_side == -m_side) {
    //         potentialMove.type = MovementType::CAPTURE;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //         break;
    //     }
    //     else {
    //         potentialMove.type = MovementType::DEFAULT;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //     }
    // }
    // for (int i = m_cell->getCoordinates().x, j = m_cell->getCoordinates().y; i < FIELD_SIDE && j >= 0; i++, j--) {
    //     if (boardModel.getCellModel(i, j).m_side == m_side) 
    //         break;
    //     else if (boardModel.getCellModel(i, j).m_side == -m_side) {
    //         potentialMove.type = MovementType::CAPTURE;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //         break;
    //     }
    //     else {
    //         potentialMove.type = MovementType::DEFAULT;
    //         potentialMove.toCellCoordinates = sf::Vector2i(i, j);
    //         m_validMoves.push_back(potentialMove);
    //     }
    // }
}

Bishop::Bishop(int side, Cell *standingOn) : Piece(side, standingOn) {
    if (side == -1)
        this->initWithPath(BLACK_BISHOP_PATH);
    else    
        this->initWithPath(WHITE_BISHOP_PATH);
    this->setSize(CELL_SIZE);
}

Bishop::~Bishop() {}

#endif  /* BISHOP_HPP */