#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <iostream>

using namespace std;


enum TeamColor 
{ 
    WHITE, 
    BLACK 
};


int absoluteValue(int value);


class ChessPiece 
{
    protected:
        TeamColor team;
        char pieceSymbol;

    public:
        ChessPiece(TeamColor teamColor, char symbol);
    
        virtual ~ChessPiece();
    
        TeamColor getTeam() const;
        char getPieceSymbol() const;

        virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const = 0;
};

#endif