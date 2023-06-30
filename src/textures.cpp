#include "textures.h"

void Textures::textureInit(SDL_Renderer* renderer, std::string texturePath, int x, int y)
{
    textureX = x;
    textureY = y;

    // White Queen Loading Surface
    surface = IMG_Load(texturePath.c_str());
    if (surface == nullptr) {
        std::cout << "Piece Surface not created" << std::endl;
    }

    // White Queen Width & Height
    textureWidth = surface->w;
    textureHeight = surface->h;

    // White Queen Texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cout << "Piece Texture not created" << std::endl;
    }

    textureRect = { textureX, textureY, textureWidth, textureHeight };
    
    SDL_FreeSurface(surface);
}

void Textures::textureOnWindow(SDL_Renderer* renderer) 
{
    SDL_RenderCopy(renderer, texture, nullptr, &textureRect);
}