#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class Queen
{
    private:

    public:
        bool isWhiteQueenMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackQueenMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};