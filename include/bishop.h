#pragma once

#include "piece.h"
#include <string>
#include <iostream>

class Bishop
{
    private:

    public:
        bool isWhiteBishopMoveLegal(std::string move, const std::vector<Piece*>& blackObjects);
        bool isBlackBishopMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects);
        void snapToPrev(const std::string& move, Piece* obj);
};