#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "piece.h"

class GameState
{
    private:
        std::string fenString;

        bool whiteToMove;
        bool blackToMove;
    public:
        int totalMoves;

        std::string piecePlacement(Piece& wQueen, Piece& wKing, Piece& wBishop1, Piece& wBishop2,
                                   Piece& wKnight1, Piece& wKnight2, Piece& wRook1, Piece& wRook2,
                                   Piece& wPawn1, Piece& wPawn2, Piece& wPawn3, Piece& wPawn4, 
                                   Piece& wPawn5, Piece& wPawn6, Piece& wPawn7, Piece& wPawn8,
                                   Piece& bQueen, Piece& bKing, Piece& bBishop1, Piece& bBishop2,
                                   Piece& bKnight1, Piece& bKnight2, Piece& bRook1, Piece& bRook2,
                                   Piece& bPawn1, Piece& bPawn2, Piece& bPawn3, Piece& bPawn4, 
                                   Piece& bPawn5, Piece& bPawn6, Piece& bPawn7, Piece& bPawn8);
        
        void activeColor();
        void downloadFen();

};

