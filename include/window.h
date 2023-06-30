#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window {
    private:
        SDL_Window* window;

    protected:
        SDL_Rect boardSquares;

    public:
        SDL_Renderer* renderer;

        void createWindow();
        void drawBoard();
    
        friend class Game;
};
