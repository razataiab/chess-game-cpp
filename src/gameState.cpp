#include "gameState.h"
#include <string>
#include <fstream>


std::string GameState::piecePlacement(Piece& wQueen, Piece& wKing, Piece& wBishop1, Piece& wBishop2,
                                      Piece& wKnight1, Piece& wKnight2, Piece& wRook1, Piece& wRook2,
                                      Piece& wPawn1, Piece& wPawn2, Piece& wPawn3, Piece& wPawn4,
                                      Piece& wPawn5, Piece& wPawn6, Piece& wPawn7, Piece& wPawn8,
                                      Piece& bQueen, Piece& bKing, Piece& bBishop1, Piece& bBishop2,
                                      Piece& bKnight1, Piece& bKnight2, Piece& bRook1, Piece& bRook2,
                                      Piece& bPawn1, Piece& bPawn2, Piece& bPawn3, Piece& bPawn4,
                                      Piece& bPawn5, Piece& bPawn6, Piece& bPawn7, Piece& bPawn8)
{
    // Initialize the FEN string
    fenString = "";

    int coordinates[8][8][2] =
    {
        { {50, 90},  {130, 90},  {210, 90},  {290, 90},  {370, 90},  {450, 90},  {530, 90},  {610, 90}  },
        { {50, 170}, {130, 170}, {210, 170}, {290, 170}, {370, 170}, {450, 170}, {530, 170}, {610, 170} },
        { {50, 250}, {130, 250}, {210, 250}, {290, 250}, {370, 250}, {450, 250}, {530, 250}, {610, 250} },
        { {50, 330}, {130, 330}, {210, 330}, {290, 330}, {370, 330}, {450, 330}, {530, 330}, {610, 330} },
        { {50, 410}, {130, 410}, {210, 410}, {290, 410}, {370, 410}, {450, 410}, {530, 410}, {610, 410} },
        { {50, 490}, {130, 490}, {210, 490}, {290, 490}, {370, 490}, {450, 490}, {530, 490}, {610, 490} },
        { {50, 570}, {130, 570}, {210, 570}, {290, 570}, {370, 570}, {450, 570}, {530, 570}, {610, 570} },
        { {50, 650}, {130, 650}, {210, 650}, {290, 650}, {370, 650}, {450, 650}, {530, 650}, {610, 650} }
    };

    // Iterate over the ranks (rows) in reverse order
    for (int rank = 7; rank >= 0; --rank)
    {
        std::string rankString; // String for the current rank
        int emptySpaces = 0; // Counter for empty spaces in a rank

        // Iterate over the files (columns)
        for (int file = 0; file < 8; ++file)
        {
            bool foundPiece = false;

            // Retrieve the piece at the current coordinate
            Piece* piece = nullptr;
            for (Piece* p : {&bQueen, &bKing, &bBishop1, &bBishop2, &bKnight1, &bKnight2, &bRook1, &bRook2, 
                             &bPawn1, &bPawn2, &bPawn3, &bPawn4, &bPawn5, &bPawn6, &bPawn7, &bPawn8,
                             &wQueen, &wKing, &wBishop1, &wBishop2, &wKnight1, &wKnight2, &wRook1, &wRook2, 
                             &wPawn1, &wPawn2, &wPawn3, &wPawn4, &wPawn5, &wPawn6, &wPawn7, &wPawn8})
            {
                if (p == nullptr)
                {
                    throw std::runtime_error("Invalid Piece object: nullptr encountered.");
                }
                
                if (coordinates[rank][file][0] == p->pieceX && coordinates[rank][file][1] == p->pieceY)
                {
                    piece = p;
                    break;
                }
            }

            // If a piece was found at the current coordinate
            if (piece != nullptr)
            {
                if (emptySpaces > 0)
                {
                    rankString += std::to_string(emptySpaces);
                    emptySpaces = 0; // Reset the counter
                }
                rankString += piece->PieceChar;
                foundPiece = true;
            }

            // If no piece was found, increment the emptySpaces counter
            if (!foundPiece)
            {
                ++emptySpaces;

                // Check if it's the last file and there are empty spaces to be appended
                if (file == 7)
                {
                    rankString += std::to_string(emptySpaces);
                    emptySpaces = 0; // Reset the counter
                }
            }
        }

        // Prepend the rank string to the fenString
        if (rank < 7)
        {
            fenString = "/" + fenString;
        }
        fenString = rankString + fenString;
    }

    activeColor();
    fenString = fenString + " ";

    if (whiteToMove)
    {
        fenString = fenString + "w";
    }

    else
    {
        fenString = fenString + "b";
    }

    return fenString;
}



void GameState::activeColor()
{
    // Assuming White always starts, check if the total number of moves is even or odd
    if (totalMoves % 2 == 0)
    {
        whiteToMove = true;  // It's White's turn
        blackToMove = false; // Reset blackToMove
    }
    if (!(totalMoves % 2 == 0))
    {
        whiteToMove = false; // Reset whiteToMove
        blackToMove = true;  // It's Black's turn
    }
}


void GameState::downloadFen()
{
    // Create a file stream
    std::ofstream file;
    
    // Open the file in binary mode
    file.open("fen_file.txt", std::ios::out | std::ios::binary);
    
    // Check if the file is open
    if (file.is_open())
    {
        // Write the FEN string to the file
        file << fenString;
        
        // Close the file
        file.close();
        
        std::cout << "FEN file downloaded successfully." << std::endl;
    }
    else
    {
        std::cout << "Unable to open the file for writing." << std::endl;
    }
}