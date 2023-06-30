#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "piece.h"

void Piece::pieceInit(SDL_Renderer* renderer, std::string filePath) {
    // Load the image surface for the piece
    pieceSurface = IMG_Load(filePath.c_str());
    if (pieceSurface == nullptr) {
        std::cout << "Piece Surface not created" << std::endl;
    }

    // Get the width and height of the piece
    pieceWidth = pieceSurface->w;
    pieceHeight = pieceSurface->h;

    // Create the texture from the surface
    pieceTexture = SDL_CreateTextureFromSurface(renderer, pieceSurface);
    if (pieceTexture == nullptr) {
        std::cout << "Piece Texture not created" << std::endl;
    }

    isPieceClicked = false;
}

Piece::~Piece() {
    // Deallocate memory for the piece surface
    SDL_FreeSurface(pieceSurface);
}

void Piece::pieceOnWindow(SDL_Renderer* renderer) {
    // Set the position and size of the piece rectangle
    pieceRect = { pieceX, pieceY, pieceWidth, pieceHeight };
    
    // Render the piece texture to the renderer
    SDL_RenderCopy(renderer, pieceTexture, nullptr, &pieceRect);
}

void Piece::pieceMovement() 
{
    // Get the current mouse position
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    
    // Check if the mouse is within the bounds of the piece
    if (mouseX >= pieceX && mouseX < pieceX + 80 && mouseY >= pieceY && mouseY < pieceY + 80) {
        isPieceClicked = true;
    }
}

void Piece::pieceDropping() {
    if (isPieceClicked) {
        // Get the current mouse position
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        
        // Calculate the new position for the piece based on the mouse position
        pieceX = ((mouseX - 40) / 80) * 80 + 40 + 80 / 2 - pieceWidth / 2;
        pieceY = ((mouseY - 80) / 80) * 80 + 80 + 80 / 2 - pieceHeight / 2;
    }
    isPieceClicked = false;
}

void Piece::pieceDragging() {
    if (isPieceClicked) {
        // Get the current mouse position
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        
        // Update the position of the piece based on the mouse position
        pieceX = mouseX - pieceWidth / 2;
        pieceY = mouseY - pieceHeight / 2;
    }
}

std::string Piece::getPieceSquare() {
    // Calculate the file and rank of the piece based on its position
    int x = pieceX;
    int y = pieceY;

    int file = (x - 45) / 80;
    int rank = 7 - (y - 80) / 80;

    // Convert the file and rank to characters
    char fileChar = 'a' + file;
    char rankChar = '1' + rank;

    // Combine the file and rank characters to form the square string
    std::string square;
    square += fileChar;
    square += rankChar;

    return square;
}

void Piece::destroyTexture()
{
    // Destroy the piece texture
    SDL_DestroyTexture(pieceTexture);
}
