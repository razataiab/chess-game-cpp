#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class Pawn
{
    private:

    public:
        bool isWhitePawnMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackPawnMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};