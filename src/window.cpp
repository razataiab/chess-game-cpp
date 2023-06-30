#include "window.h"
#include "piece.h"

const int WINDOW_WIDTH = 1100;
const int WINDOW_HEIGHT = 800;

void Window::createWindow() 
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Chess Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::drawBoard() 
{
    // Draw the chessboard
    boardSquares.y = 80;
    boardSquares.w = 80;
    boardSquares.h = 80;

    for (int a = 0; a < 8; a++) 
    {
        boardSquares.x = 80;
        for (int b = 0; b < 8; b++) 
        {
            if ((a + b) % 2 == 0) 
            {
                SDL_SetRenderDrawColor(renderer, 245, 245, 220, 0);
            } 
            else if ((a + b) % 2 == 1) 
            {
                SDL_SetRenderDrawColor(renderer, 139, 69, 19, 0);
            }
            boardSquares.x = 40 + b * 80;
            SDL_RenderFillRect(renderer, &boardSquares);
        }
        boardSquares.y += 80;

    }
}