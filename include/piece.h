#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "window.h"


class Piece
{
    private:
        int pieceWidth;
        int pieceHeight;
        std::string PiecePath;
        SDL_Rect pieceRect;
        SDL_Surface* pieceSurface;
        SDL_Texture* pieceTexture;

    protected:

    public:
        int totalMoves;
        bool isPieceClicked;
        std::string move;
        int pieceX; 
        int pieceY;
        char PieceChar;
        void pieceInit(SDL_Renderer* renderer, std::string filePath);
        void pieceOnWindow(SDL_Renderer* renderer);
        void pieceMovement();
        void pieceDropping();
        void pieceDragging();
        void destroyTexture();
        std::string getPieceSquare();

        ~Piece();
};