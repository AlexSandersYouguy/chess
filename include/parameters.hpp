#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <SFML/Graphics.hpp>

constexpr unsigned int FIELD_SIDE = 8;
constexpr unsigned int ANIMATION_TIME = 10; // required number of frames per animation
constexpr unsigned short int FRAMERATE_LIMIT = 60;
sf::Vector2f WINDOW_SIZE;
sf::Vector2f BORDER_SIZE;
sf::Vector2f CELL_SIZE;
sf::Vector2f FIELD_START;
sf::Vector2f BORDER_THICKNESS;

#define BACKGROUND_COLOR (sf::Color(49, 46, 43))
#define BLACK_KING_PATH "assets/images/blackKing.png"
#define BLACK_QUEEN_PATH "assets/images/blackQueen.png"
#define BLACK_ROOK_PATH "assets/images/blackRook.png"
#define BLACK_BISHOP_PATH "assets/images/blackBishop.png"
#define BLACK_KNIGHT_PATH "assets/images/blackKnight.png"
#define BLACK_PAWN_PATH "assets/images/blackPawn.png"
#define WHITE_KING_PATH "assets/images/whiteKing.png"
#define WHITE_QUEEN_PATH "assets/images/whiteQueen.png"
#define WHITE_ROOK_PATH "assets/images/whiteRook.png"
#define WHITE_BISHOP_PATH "assets/images/whiteBishop.png"
#define WHITE_KNIGHT_PATH "assets/images/whiteKnight.png"
#define WHITE_PAWN_PATH "assets/images/whitePawn.png"
#define BLACK_CELL_PATH "assets/images/blackCell.png"
#define WHITE_CELL_PATH "assets/images/whiteCell.png"
#define BORDER_PATH "assets/images/boardBorder.png"
#define MAIN_ICON_PATH "assets/images/mainIcon.png"
#define WINDOW_TITLE "Chess Game"

enum class PieceType {
    KING,
    QUEEN,
    ROOK, 
    BISHOP,
    KNIGHT,
    PAWN,
    NONE  
};

#define BLACK (-1)
#define WHITE (1)
#define EMPTY (0)
#define BOTH_SIDES (-11)

enum MovementType { 
    DEFAULT, 
    CAPTURE, 
    SHORT_CASTLING, 
    LONG_CASTLING, 
    EN_PASSANT, 
    PROMOTION 
};

#endif  /* PARAMETERS_HPP */