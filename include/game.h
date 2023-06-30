#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include <SDL2/SDL.h>


#include "window.h"
#include "piece.h"
#include "gameState.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include "textures.h"

class Game
{
    private:
        SDL_Event event;

    public:
        void gameInit();

        
};
