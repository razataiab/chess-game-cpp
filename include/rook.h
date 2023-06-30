#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class Rook
{
    private:

    public:
        bool isWhiteRookMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackRookMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};