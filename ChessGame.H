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


class Queen : public ChessPiece 
{
public:
    Queen(TeamColor color);
    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};


class King : public ChessPiece 
{
    public:
        King(TeamColor color);
    
        bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const override;
};


class ChessBoard 
{
    private:
        ChessPiece* grid[8][8];

    public:
        ChessBoard();
    
        ~ChessBoard();
    
        void initializePieces();
        void display();
        bool movePiece(int sRow, int sCol, int eRow, int eCol, TeamColor playerTurn);
};


class ChessEngine 
{
    private:
        ChessBoard board;
        TeamColor activeTurn;

    public:
        ChessEngine();
        void play();
};


#endif