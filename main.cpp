#include "ChessGame.h"


int absoluteValue(int value) 
{
    return (value < 0) ? -value : value;
}


ChessPiece::ChessPiece(TeamColor teamColor, char symbol) : team(teamColor), pieceSymbol(symbol) {}

ChessPiece::~ChessPiece() {}

TeamColor ChessPiece::getTeam() const 
{ 
    return team; 
}

char ChessPiece::getPieceSymbol() const 
{ 
    return pieceSymbol; 
}


Pawn::Pawn(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'P' : 'p') {}

bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
    int direction = (team == WHITE) ? -1 : 1; 
    int initialRow = (team == WHITE) ? 6 : 1;

    if (startCol == endCol && (endRow - startRow == direction)) 
    {
        if (grid[endRow][endCol] == nullptr) 
        {
            return true;
        }
    }

    if ((startCol == endCol) && (startRow == initialRow) && (endRow - startRow == 2 * direction)) 
    {
        if ((grid[startRow + direction][startCol] == nullptr) && (grid[endRow][endCol] == nullptr)) 
        {
            return true;
        }
    }

    if ((absoluteValue(endCol - startCol) == 1) && (endRow - startRow == direction)) 
    {
        if ((grid[endRow][endCol] != nullptr) && (grid[endRow][endCol]->getTeam() != this->team)) 
        {
            return true;
        }
    }

    return false;
}