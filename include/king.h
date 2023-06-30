#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class King
{
    private:

    public:
        bool isWhiteKingMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackKingMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};