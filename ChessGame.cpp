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


Rook::Rook(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'R' : 'r') {}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
    if ((startRow != endRow) && (startCol != endCol)) 
    {
        return false;
    }

    int rowDir = (endRow == startRow) ? 0 : (endRow > startRow ? 1 : -1);
    int colDir = (endCol == startCol) ? 0 : (endCol > startCol ? 1 : -1);
    
    int currR = startRow + rowDir;
    int currC = startCol + colDir;

    while (currR != endRow || currC != endCol) 
    {
        if (grid[currR][currC] != nullptr) 
        {
            return false;
        }
        
        currR += rowDir;
        currC += colDir;
    }

    if((grid[endRow][endCol] == nullptr) || (grid[endRow][endCol]->getTeam() != team)) 
    {
        return true;
    }

    return false;
}


Knight::Knight(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'N' : 'n') {}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
    int rDiff = absoluteValue(endRow - startRow);
    int cDiff = absoluteValue(endCol - startCol);
    
    if (((rDiff == 2 && cDiff == 1) || (rDiff == 1 && cDiff == 2)))
    {
        if((grid[endRow][endCol] == nullptr) || (grid[endRow][endCol]->getTeam() != team)) 
        {
            return true;
        }
    }

    return false;
}


Bishop::Bishop(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'B' : 'b') {}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
    if (absoluteValue(endRow - startRow) != absoluteValue(endCol - startCol)) 
    {
        return false;
    }
    
    int rowDir = (endRow == startRow) ? 0 : (endRow > startRow ? 1 : -1);
    int colDir = (endCol == startCol) ? 0 : (endCol > startCol ? 1 : -1);
    
    int currR = startRow + rowDir;
    int currC = startCol + colDir;
    
    while (currR != endRow && currC != endCol) 
    {
        if (grid[currR][currC] != nullptr) 
        {
            return false;
        }

        currR += rowDir;
        currC += colDir;
    }

    if((grid[endRow][endCol] == nullptr) || (grid[endRow][endCol]->getTeam() != team)) 
    {
        return true;
    }

    return false;
}


Queen::Queen(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'Q' : 'q') {}

bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
    Rook tempRook(team);
    
    if (tempRook.isValidMove(startRow, startCol, endRow, endCol, grid)) 
    {
        return true;
    }

    Bishop tempBishop(team);
    if (tempBishop.isValidMove(startRow, startCol, endRow, endCol, grid)) 
    {
        return true;
    }

    return false;
}


King::King(TeamColor color) : ChessPiece(color, (color == WHITE) ? 'K' : 'k') {}

bool King::isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* grid[8][8]) const 
{
   int rDiff = absoluteValue(endRow - startRow);
   int cDiff = absoluteValue(endCol - startCol);

   if ((rDiff <= 1) && (cDiff <= 1)) 
   {
       if((grid[endRow][endCol] == nullptr) || (grid[endRow][endCol]->getTeam() != team)) 
       {
           return true;
       }
   }

    return false;
}


ChessBoard::ChessBoard() 
{
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            grid[i][j] = nullptr;
        }
    }
    initializePieces();
}

ChessBoard::~ChessBoard() 
{
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            delete grid[i][j];
        }
    }
}

void ChessBoard::initializePieces() 
{
    grid[0][0] = new Rook(BLACK);   
    grid[0][7] = new Rook(BLACK);
    grid[0][1] = new Knight(BLACK); 
    grid[0][6] = new Knight(BLACK);
    grid[0][2] = new Bishop(BLACK); 
    grid[0][5] = new Bishop(BLACK);
    grid[0][3] = new Queen(BLACK);  
    grid[0][4] = new King(BLACK);
    for (int i = 0; i < 8; i++) 
    {
        grid[1][i] = new Pawn(BLACK);
    }

    grid[7][0] = new Rook(WHITE);   
    grid[7][7] = new Rook(WHITE);
    grid[7][1] = new Knight(WHITE); 
    grid[7][6] = new Knight(WHITE);
    grid[7][2] = new Bishop(WHITE); 
    grid[7][5] = new Bishop(WHITE);
    grid[7][3] = new Queen(WHITE);  
    grid[7][4] = new King(WHITE);
    for (int i = 0; i < 8; i++) 
    {
        grid[6][i] = new Pawn(WHITE);
    }
}

void ChessBoard::display() 
{
    cout << "\n    0 1 2 3 4 5 6 7\n   -----------------\n";
    for (int i = 0; i < 8; i++) 
    {
        cout << i << " | ";
        for (int j = 0; j < 8; j++) 
        {
            if (grid[i][j] == nullptr) 
            {
                cout << ". ";
            }
            else 
            {
                cout << grid[i][j]->getPieceSymbol() << " ";
            }
        }
        cout << "|\n";
    }
    cout << "   -----------------\n";
}

bool ChessBoard::movePiece(int sRow, int sCol, int eRow, int eCol, TeamColor playerTurn) 
{
    if (sRow < 0 || sRow > 7 || sCol < 0 || sCol > 7 || eRow < 0 || eRow > 7 || eCol < 0 || eCol > 7) 
    {
        return false;
    }

    ChessPiece* activePiece = grid[sRow][sCol];
    
    if (activePiece == nullptr || activePiece->getTeam() != playerTurn) 
    {
        return false;
    }

    if (activePiece->isValidMove(sRow, sCol, eRow, eCol, grid)) 
    {
        if (grid[eRow][eCol] != nullptr) 
        {
            char target = grid[eRow][eCol]->getPieceSymbol();
            if (target == 'K' || target == 'k') 
            {
                cout << "\nGAME OVER! " << (playerTurn == WHITE ? "WHITE" : "BLACK") << " CAPTURED THE KING!\n";
                exit(0); 
            }
            delete grid[eRow][eCol]; 
        }

        grid[eRow][eCol] = grid[sRow][sCol];
        grid[sRow][sCol] = nullptr;

        return true;
    }

    return false;
}

ChessEngine::ChessEngine() : activeTurn(WHITE) {}
void ChessEngine::play() 
{
    cout << "=================================\n  OOP SEMESTER PROJECT: CHESS\n=================================\n";
    while (true) 
    {
        board.display();

        cout << "\n" << (activeTurn == WHITE ? "WHITE" : "BLACK") << "'S TURN" << endl;

        int sR, sC, eR, eC;

        cout << "Enter Source (Row Col): "; 
        if (!(cin >> sR >> sC)) break;

        cout << "Enter Target (Row Col): "; 
        if (!(cin >> eR >> eC)) break;

        if (board.movePiece(sR, sC, eR, eC, activeTurn)) 
        {
            activeTurn = (activeTurn == WHITE) ? BLACK : WHITE;
        }
        else 
        {
            cout << "\n[ERROR] Invalid move. Try again.\n";
        }
    }
}