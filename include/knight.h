#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class Knight
{
    private:

    public:
        bool isWhiteKnightMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackKnightMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};