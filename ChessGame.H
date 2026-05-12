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


class Pawn : public ChessPiece 
{
    public:
        Pawn(TeamColor color);
    
        bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};


class Rook : public ChessPiece 
{
    public:
        Rook(TeamColor color);
    
        bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};


class Knight : public ChessPiece 
{
    public:
        Knight(TeamColor color);
        bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};


class Bishop : public ChessPiece 
{
    public:
        Bishop(TeamColor color);
    
        bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};

#endif