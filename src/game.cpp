#include "game.h"

void Game::gameInit()
{
    Window window;

    GameState gamestate;

    Pawn pawn;
    Rook rook;
    Bishop bishop;
    Queen queen;
    King king;
    Knight knight;

    std::vector<Piece*> whiteObjects;
    std::vector<Piece*> blackObjects;

    std::vector<Piece*> whitePawnObjects;
    std::vector<Piece*> blackPawnObjects;

    std::vector<Piece*> whiteQueenObject;
    std::vector<Piece*> blackQueenObject;

    std::vector<Piece*> whiteKingObject;
    std::vector<Piece*> blackKingObject;
    std::vector<Piece*> BishopObjects;
    std::vector<Piece*> KnightObjects;
    std::vector<Piece*> RookObjects;

    std::vector<Piece*> whiteRookObjects;
    std::vector<Piece*> blackRookObjects;

    std::vector<Piece*> whiteBishopObjects;
    std::vector<Piece*> blackBishopObjects;

    std::vector<Piece*> whiteKnightObjects;
    std::vector<Piece*> blackKnightObjects;


    Piece wQueen, wBishop1, wBishop2, wKing, wRook1, wRook2, wKnight1, wKnight2,
          wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8;

    Piece bQueen, bBishop1, bBishop2, bKing, bRook1, bRook2, bKnight1, bKnight2,
          bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8;

    blackObjects.push_back(&bQueen);   blackObjects.push_back(&bKing);
    blackObjects.push_back(&bBishop1); blackObjects.push_back(&bBishop2);
    blackObjects.push_back(&bKnight1); blackObjects.push_back(&bKnight2);
    blackObjects.push_back(&bRook1);   blackObjects.push_back(&bRook2);
    blackObjects.push_back(&bPawn1);   blackObjects.push_back(&bPawn2);
    blackObjects.push_back(&bPawn3);   blackObjects.push_back(&bPawn4);
    blackObjects.push_back(&bPawn5);   blackObjects.push_back(&bPawn6);
    blackObjects.push_back(&bPawn7);   blackObjects.push_back(&bPawn8);

    whiteQueenObject.push_back(&wQueen);   whiteKingObject.push_back(&wKing);
    BishopObjects.push_back(&wBishop1); BishopObjects.push_back(&wBishop2);
    KnightObjects.push_back(&wKnight1); KnightObjects.push_back(&wKnight2);
    RookObjects.push_back(&wRook1);   RookObjects.push_back(&wRook2);

    blackQueenObject.push_back(&bQueen);   blackKingObject.push_back(&bKing);
    BishopObjects.push_back(&bBishop1); BishopObjects.push_back(&bBishop2);
    KnightObjects.push_back(&bKnight1); KnightObjects.push_back(&bKnight2);
    RookObjects.push_back(&bRook1);   RookObjects.push_back(&bRook2);
    

    whitePawnObjects.push_back(&wPawn1);   whitePawnObjects.push_back(&wPawn2);
    whitePawnObjects.push_back(&wPawn3);   whitePawnObjects.push_back(&wPawn4);
    whitePawnObjects.push_back(&wPawn5);   whitePawnObjects.push_back(&wPawn6);
    whitePawnObjects.push_back(&wPawn7);   whitePawnObjects.push_back(&wPawn8);

    blackPawnObjects.push_back(&bPawn1);   blackPawnObjects.push_back(&bPawn2);
    blackPawnObjects.push_back(&bPawn3);   blackPawnObjects.push_back(&bPawn4);
    blackPawnObjects.push_back(&bPawn5);   blackPawnObjects.push_back(&bPawn6);
    blackPawnObjects.push_back(&bPawn7);   blackPawnObjects.push_back(&bPawn8);

    whiteRookObjects.push_back(&wRook1);   whiteRookObjects.push_back(&wRook2);
    blackRookObjects.push_back(&bRook1);   blackRookObjects.push_back(&bRook2);

    whiteBishopObjects.push_back(&wBishop1);   whiteBishopObjects.push_back(&wBishop2);
    blackBishopObjects.push_back(&bBishop1);   blackBishopObjects.push_back(&bBishop2);

    whiteKnightObjects.push_back(&wKnight1);   whiteKnightObjects.push_back(&wKnight2);
    blackKnightObjects.push_back(&bKnight1);   blackKnightObjects.push_back(&bKnight2);



    wQueen.PieceChar = 'Q';    wKing.PieceChar = 'K';
    wBishop1.PieceChar = 'B';  wBishop2.PieceChar = 'B';
    wKnight1.PieceChar = 'N';  wKnight2.PieceChar = 'N';
    wRook1.PieceChar = 'R';    wRook2.PieceChar = 'R';
    wPawn1.PieceChar = 'P';    wPawn2.PieceChar = 'P';
    wPawn3.PieceChar = 'P';    wPawn4.PieceChar = 'P';
    wPawn5.PieceChar = 'P';    wPawn6.PieceChar = 'P';
    wPawn7.PieceChar = 'P';    wPawn8.PieceChar = 'P';

    bQueen.PieceChar = 'q';    bKing.PieceChar = 'k';
    bBishop1.PieceChar = 'b';  bBishop2.PieceChar = 'b';
    bKnight1.PieceChar = 'n';  bKnight2.PieceChar = 'n';
    bRook1.PieceChar = 'r';    bRook2.PieceChar = 'r';
    bPawn1.PieceChar = 'p';    bPawn2.PieceChar = 'p';
    bPawn3.PieceChar = 'p';    bPawn4.PieceChar = 'p';
    bPawn5.PieceChar = 'p';    bPawn6.PieceChar = 'p';
    bPawn7.PieceChar = 'p';    bPawn8.PieceChar = 'p';

    wQueen.pieceX = 290;   wQueen.pieceY = 650;    wKing.pieceX = 370;     wKing.pieceY = 650;
    wBishop1.pieceX = 210; wBishop1.pieceY = 650;  wBishop2.pieceX = 450;  wBishop2.pieceY = 650;
    wKnight1.pieceX = 130; wKnight1.pieceY = 650;  wKnight2.pieceX = 530;  wKnight2.pieceY = 650;
    wRook1.pieceX = 50;    wRook1.pieceY = 650;    wRook2.pieceX = 610;    wRook2.pieceY = 650;
    wPawn1.pieceX = 50;    wPawn1.pieceY = 570;    wPawn2.pieceX = 130;    wPawn2.pieceY = 570;
    wPawn3.pieceX = 210;   wPawn3.pieceY = 570;    wPawn4.pieceX = 290;    wPawn4.pieceY = 570;
    wPawn5.pieceX = 370;   wPawn5.pieceY = 570;    wPawn6.pieceX = 450;    wPawn6.pieceY = 570;
    wPawn7.pieceX = 530;   wPawn7.pieceY = 570;    wPawn8.pieceX = 610;    wPawn8.pieceY = 570;

    bQueen.pieceX = 370;   bQueen.pieceY = 90;     bKing.pieceX = 290;    bKing.pieceY = 90;
    bBishop1.pieceX = 210; bBishop1.pieceY = 90;   bBishop2.pieceX = 450; bBishop2.pieceY = 90;
    bKnight1.pieceX = 130; bKnight1.pieceY = 90;   bKnight2.pieceX = 530; bKnight2.pieceY = 90;
    bRook1.pieceX = 50;    bRook1.pieceY = 90;     bRook2.pieceX = 610;   bRook2.pieceY = 90;
    bPawn1.pieceX = 50;    bPawn1.pieceY = 170;    bPawn2.pieceX = 130;   bPawn2.pieceY = 170;
    bPawn3.pieceX = 210;   bPawn3.pieceY = 170;    bPawn4.pieceX = 290;   bPawn4.pieceY = 170;
    bPawn5.pieceX = 370;   bPawn5.pieceY = 170;    bPawn6.pieceX = 450;   bPawn6.pieceY = 170;
    bPawn7.pieceX = 530;   bPawn7.pieceY = 170;    bPawn8.pieceX = 610;   bPawn8.pieceY = 170;

    wPawn1.move = "a2";   wPawn2.move = "b2";
    wPawn3.move = "c2";   wPawn4.move = "d2";
    wPawn5.move = "e2";   wPawn6.move = "f2";
    wPawn7.move = "g2";   wPawn8.move = "h2";

    bPawn1.move = "a7";   bPawn2.move = "b7";
    bPawn3.move = "c7";   bPawn4.move = "d7";
    bPawn5.move = "e7";   bPawn6.move = "f7";
    bPawn7.move = "g7";   bPawn8.move = "h7";

    wRook1.move = "a1";   wRook2.move = "h1";
    bRook1.move = "a7";   bRook2.move = "h7";

    window.createWindow();

    // Initialize the piece object
    wQueen.pieceInit(window.renderer, "assets/whiteQueen.png");    wKing.pieceInit(window.renderer, "assets/whiteKing.png");
    wBishop1.pieceInit(window.renderer, "assets/whiteBishop.png"); wBishop2.pieceInit(window.renderer, "assets/whiteBishop.png");
    wRook1.pieceInit(window.renderer, "assets/whiteRook.png");     wRook2.pieceInit(window.renderer, "assets/whiteRook.png");
    wKnight1.pieceInit(window.renderer, "assets/whiteKnight.png"); wKnight2.pieceInit(window.renderer, "assets/whiteKnight.png");
    wPawn1.pieceInit(window.renderer, "assets/whitePawn.png");     wPawn2.pieceInit(window.renderer, "assets/whitePawn.png");
    wPawn3.pieceInit(window.renderer, "assets/whitePawn.png");     wPawn4.pieceInit(window.renderer, "assets/whitePawn.png");
    wPawn5.pieceInit(window.renderer, "assets/whitePawn.png");     wPawn6.pieceInit(window.renderer, "assets/whitePawn.png");
    wPawn7.pieceInit(window.renderer, "assets/whitePawn.png");     wPawn8.pieceInit(window.renderer, "assets/whitePawn.png");

    bQueen.pieceInit(window.renderer, "assets/blackQueen.png");    bKing.pieceInit(window.renderer, "assets/blackKing.png");
    bBishop1.pieceInit(window.renderer, "assets/blackBishop.png"); bBishop2.pieceInit(window.renderer, "assets/blackBishop.png");
    bRook1.pieceInit(window.renderer, "assets/blackRook.png");     bRook2.pieceInit(window.renderer, "assets/blackRook.png");
    bKnight1.pieceInit(window.renderer, "assets/blackKnight.png"); bKnight2.pieceInit(window.renderer, "assets/blackKnight.png");
    bPawn1.pieceInit(window.renderer, "assets/blackPawn.png");     bPawn2.pieceInit(window.renderer, "assets/blackPawn.png");
    bPawn3.pieceInit(window.renderer, "assets/blackPawn.png");     bPawn4.pieceInit(window.renderer, "assets/blackPawn.png");
    bPawn5.pieceInit(window.renderer, "assets/blackPawn.png");     bPawn6.pieceInit(window.renderer, "assets/blackPawn.png");
    bPawn7.pieceInit(window.renderer, "assets/blackPawn.png");     bPawn8.pieceInit(window.renderer, "assets/blackPawn.png");

    // Create and initialize textures
    Textures logo, anX, anY, github, linkedin, player1, player2, fen, fenPlaceholder;
    logo.textureInit(window.renderer, "assets/logoforgame.bmp", 750, 90);
    anX.textureInit(window.renderer, "assets/ANX.bmp", 10, 110);
    anY.textureInit(window.renderer, "assets/ANY.bmp", 74, 725);
    github.textureInit(window.renderer, "assets/github.bmp", 770, 530);
    linkedin.textureInit(window.renderer, "assets/linkedin.bmp", 940, 530);
    player1.textureInit(window.renderer, "assets/player1.bmp", 320, 748);
    player2.textureInit(window.renderer, "assets/player2.bmp", 320, 27);
    fen.textureInit(window.renderer, "assets/downloadButton.png", 995, 702);
    fenPlaceholder.textureInit(window.renderer, "assets/fenPlaceholder.png", 885, 705);

    bool quit = false;
    while (!quit) 
    {
       while (SDL_PollEvent(&event)) 
       {
           if (event.type == SDL_QUIT) 
           {
               quit = true;
           }

           else if (event.type == SDL_MOUSEBUTTONDOWN)
           {
               for (Piece* wQobj : whiteQueenObject) 
               {
                   wQobj->pieceMovement();
               }

               for (Piece* bQobj : blackQueenObject) 
               {
                   bQobj->pieceMovement();
               }

               for (Piece* wKobj : whiteKingObject) 
               {
                   wKobj->pieceMovement();
               }

               for (Piece* bKobj : blackKingObject) 
               {
                   bKobj->pieceMovement();
               }

               for (Piece* Bobj : BishopObjects) 
               {
                   Bobj->pieceMovement();
               }

               for (Piece* Knobj : KnightObjects) 
               {
                   Knobj->pieceMovement();
               }

               for (Piece* Robj : RookObjects) 
               {
                   Robj->pieceMovement();
               }

               for (Piece* wPawnobj : whitePawnObjects) 
               {
                   wPawnobj->pieceMovement();
               }

               for (Piece* bPawnobj : blackPawnObjects) 
               {
                   bPawnobj->pieceMovement();
               }

                int mouse_x, mouse_y;
                SDL_GetMouseState(&mouse_x, &mouse_y);

                // SDL_Rect clickRectfenph = { mouse_x, mouse_y, 1, 1 };
                // SDL_Rect clickRectfen = { mouse_x, mouse_y, 1, 1 };
                // if (SDL_HasIntersection(&clickRectfenph, &fenPlaceholder.textureRect) || SDL_HasIntersection(&clickRectfen, &fen.textureRect))
                // {
                //     gamestate.piecePlacement(wQueen, wKing, wBishop1, wBishop2, wKnight1, wKnight2, wRook1, wRook2,
                //                             wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8,
                //                             bQueen, bKing, bBishop1, bBishop2, bKnight1, bKnight2, bRook1, bRook2,
                //                             bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8);
                //     gamestate.downloadFen();
                // }

                SDL_Rect clickRectlink = { mouse_x, mouse_y, 1, 1 };
                if (SDL_HasIntersection(&clickRectlink, &linkedin.textureRect))
                {
                   system("open https://www.linkedin.com/in/razataiab/");
                }

                SDL_Rect clickRectgit = { mouse_x, mouse_y, 1, 1 };
                if (SDL_HasIntersection(&clickRectgit, &github.textureRect))
                {
                   system("open https://github.com/razataiab");
                }
           }

           else if (event.type == SDL_MOUSEMOTION)
           {
               for (Piece* wQobj : whiteQueenObject) 
               {
                   wQobj->pieceDragging();
               }

               for (Piece* bQobj : blackQueenObject) 
               {
                   bQobj->pieceDragging();
               }

               for (Piece* wKobj : whiteKingObject) 
               {
                   wKobj->pieceDragging();
               }

               for (Piece* bKobj : blackKingObject) 
               {
                   bKobj->pieceDragging();
               }

               for (Piece* Bobj : BishopObjects) 
               {
                   Bobj->pieceDragging();
               }

               for (Piece* Knobj : KnightObjects) 
               {
                   Knobj->pieceDragging();
               }

               for (Piece* Robj : RookObjects) 
               {
                   Robj->pieceDragging();
               }

               for (Piece* wPawnobj : whitePawnObjects) 
               {
                   wPawnobj->pieceDragging();
               }

               for (Piece* bPawnobj : blackPawnObjects) 
               {
                   bPawnobj->pieceDragging();
               }
           }


           else if (event.type == SDL_MOUSEBUTTONUP) 
           {
               for (Piece* wQobj : whiteQueenObject) 
               {
                   if (wQobj->isPieceClicked)
                   {
                       wQobj->move += wQobj->getPieceSquare();
                        if(queen.isWhiteQueenMoveLegal(wQobj->move, blackObjects))
                        {
                            wQobj->move = wQobj->move.substr(2);
                            wQobj->pieceDropping();
                        }

                        else
                        {
                            queen.snapToPrev(wQobj->move, wQobj);
                            wQobj->move = wQobj->move.substr(0, wQobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* bQobj : blackQueenObject) 
               {
                   if (bQobj->isPieceClicked)
                   {
                       bQobj->move += bQobj->getPieceSquare();
                        if(queen.isBlackQueenMoveLegal(bQobj->move, whiteObjects))
                        {
                            bQobj->move = bQobj->move.substr(2);
                            bQobj->pieceDropping();
                        }

                        else
                        {
                            queen.snapToPrev(bQobj->move, bQobj);
                            bQobj->move = bQobj->move.substr(0, bQobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* wKobj : whiteKingObject) 
               {
                   if (wKobj->isPieceClicked)
                   {
                       wKobj->move += wKobj->getPieceSquare();
                        if(king.isWhiteKingMoveLegal(wKobj->move, blackObjects))
                        {
                            wKobj->move = wKobj->move.substr(2);
                            wKobj->pieceDropping();
                        }

                        else
                        {
                            king.snapToPrev(wKobj->move, wKobj);
                            wKobj->move = wKobj->move.substr(0, wKobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* bkobj : blackKingObject) 
               {
                   if (bkobj->isPieceClicked)
                   {
                       bkobj->move += bkobj->getPieceSquare();
                        if(king.isBlackKingMoveLegal(bkobj->move, whiteObjects))
                        {
                            bkobj->move = bkobj->move.substr(2);
                            bkobj->pieceDropping();
                        }

                        else
                        {
                            king.snapToPrev(bkobj->move, bkobj);
                            bkobj->move = bkobj->move.substr(0, bkobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Knobj : whiteKnightObjects) 
               {
                   if (Knobj->isPieceClicked)
                   {
                       Knobj->move += Knobj->getPieceSquare();
                        if(knight.isWhiteKnightMoveLegal(Knobj->move, blackObjects))
                        {
                            Knobj->move = Knobj->move.substr(2);
                            Knobj->pieceDropping();
                        }

                        else
                        {
                            knight.snapToPrev(Knobj->move, Knobj);
                            Knobj->move = Knobj->move.substr(0, Knobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Knobj : blackKnightObjects) 
               {
                   if (Knobj->isPieceClicked)
                   {
                       Knobj->move += Knobj->getPieceSquare();
                        if(bishop.isBlackBishopMoveLegal(Knobj->move, whiteObjects))
                        {
                            Knobj->move = Knobj->move.substr(2);
                            Knobj->pieceDropping();
                        }

                        else
                        {
                            bishop.snapToPrev(Knobj->move, Knobj);
                            Knobj->move = Knobj->move.substr(0, Knobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Bobj : whiteBishopObjects) 
               {
                   if (Bobj->isPieceClicked)
                   {
                       Bobj->move += Bobj->getPieceSquare();
                        if(bishop.isWhiteBishopMoveLegal(Bobj->move, blackObjects))
                        {
                            Bobj->move = Bobj->move.substr(2);
                            Bobj->pieceDropping();
                        }

                        else
                        {
                            bishop.snapToPrev(Bobj->move, Bobj);
                            Bobj->move = Bobj->move.substr(0, Bobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Bobj : blackBishopObjects) 
               {
                   if (Bobj->isPieceClicked)
                   {
                       Bobj->move += Bobj->getPieceSquare();
                        if(bishop.isBlackBishopMoveLegal(Bobj->move, whiteObjects))
                        {
                            Bobj->move = Bobj->move.substr(2);
                            Bobj->pieceDropping();
                        }

                        else
                        {
                            bishop.snapToPrev(Bobj->move, Bobj);
                            Bobj->move = Bobj->move.substr(0, Bobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Robj : whiteRookObjects) 
               {
                   if (Robj->isPieceClicked)
                   {
                       Robj->move += Robj->getPieceSquare();
                        if(rook.isWhiteRookMoveLegal(Robj->move, blackObjects))
                        {
                            Robj->move = Robj->move.substr(2);
                            Robj->pieceDropping();
                        }

                        else
                        {
                            rook.snapToPrev(Robj->move, Robj);
                            Robj->move = Robj->move.substr(0, Robj->move.size() - 2);
                        }
                   }
               }

               for (Piece* Robj : blackRookObjects) 
               {
                   if (Robj->isPieceClicked)
                   {
                       Robj->move += Robj->getPieceSquare();
                        if(rook.isBlackRookMoveLegal(Robj->move, whiteObjects))
                        {
                            Robj->move = Robj->move.substr(2);
                            Robj->pieceDropping();
                        }

                        else
                        {
                            rook.snapToPrev(Robj->move, Robj);
                            Robj->move = Robj->move.substr(0, Robj->move.size() - 2);
                        }
                   }
               }


               for (Piece* wPawnobj : whitePawnObjects) 
               {
                   if (wPawnobj->isPieceClicked)
                   {
                       wPawnobj->move += wPawnobj->getPieceSquare();
                        if(pawn.isWhitePawnMoveLegal(wPawnobj->move, blackObjects))
                        {
                            wPawnobj->move = wPawnobj->move.substr(2);
                            wPawnobj->pieceDropping();
                        }

                        else
                        {
                            pawn.snapToPrev(wPawnobj->move, wPawnobj);
                            wPawnobj->move = wPawnobj->move.substr(0, wPawnobj->move.size() - 2);
                        }
                   }
               }

               for (Piece* bPawnobj : blackPawnObjects) 
               {
                   if (bPawnobj->isPieceClicked)
                   {
                       bPawnobj->move += bPawnobj->getPieceSquare();
                        if(pawn.isBlackPawnMoveLegal(bPawnobj->move, whiteObjects))
                        {
                            bPawnobj->move = bPawnobj->move.substr(2);
                            bPawnobj->pieceDropping();
                        }

                        else
                        {
                            pawn.snapToPrev(bPawnobj->move, bPawnobj);
                            bPawnobj->move = bPawnobj->move.substr(0, bPawnobj->move.size() - 2);
                        }
                   }
               }



               gamestate.totalMoves++;

                // Rest of your code
                // std::cout << gamestate.piecePlacement(wQueen, wKing, wBishop1, wBishop2, wKnight1, wKnight2, wRook1, wRook2,
                //                                       wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8,
                //                                       bQueen, bKing, bBishop1, bBishop2, bKnight1, bKnight2, bRook1, bRook2,
                //                                       bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8) << std::endl;
            }

            // Clear the window.renderer
            SDL_SetRenderDrawColor(window.renderer, 31, 31, 31, 0);
            SDL_RenderClear(window.renderer);

            // Draw the chessboard
            window.drawBoard();

            for (Piece* wQobj : whiteQueenObject) 
            {
                wQobj->pieceOnWindow(window.renderer);
            }

            for (Piece* bQobj : blackQueenObject) 
            {
                bQobj->pieceOnWindow(window.renderer);
            }

            for (Piece* wKobj : whiteKingObject) 
            {
                wKobj->pieceOnWindow(window.renderer);
            }

            for (Piece* bKobj : blackKingObject) 
            {
                bKobj->pieceOnWindow(window.renderer);
            }
            
            for (Piece* Bobj : BishopObjects) 
            {
                Bobj->pieceOnWindow(window.renderer);
            }

            for (Piece* Knobj : KnightObjects) 
            {
                Knobj->pieceOnWindow(window.renderer);
            }

            for (Piece* Robj : RookObjects) 
            {
                Robj->pieceOnWindow(window.renderer);
            }

            for (Piece* wPawnobj : whitePawnObjects) 
            {
                wPawnobj->pieceOnWindow(window.renderer);
            }

            for (Piece* bPawnobj : blackPawnObjects) 
            {
                bPawnobj->pieceOnWindow(window.renderer);
            }

            logo.textureOnWindow(window.renderer);
            anX.textureOnWindow(window.renderer);
            anY.textureOnWindow(window.renderer);
            github.textureOnWindow(window.renderer);
            linkedin.textureOnWindow(window.renderer);
            player1.textureOnWindow(window.renderer);
            player2.textureOnWindow(window.renderer);
            fen.textureOnWindow(window.renderer);
            fenPlaceholder.textureOnWindow(window.renderer);

            // Update the window
            SDL_RenderPresent(window.renderer);
        }
    }
}