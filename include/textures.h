#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <iostream>

#include "window.h"

class Textures
{
    public:
        int textureX;
        int textureY;

        std::string texturePath;

        SDL_Surface* surface;
        SDL_Texture* texture;

        int textureWidth;
        int textureHeight;

        SDL_Rect textureRect;

        void textureInit(SDL_Renderer* renderer, std::string texturePath, int x, int y);
        void textureOnWindow(SDL_Renderer* renderer);
};