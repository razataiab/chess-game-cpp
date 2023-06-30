#include "pawn.h"
#include <vector>


bool Pawn::isWhitePawnMoveLegal(std::string move, const std::vector<Piece*>& blackObjects)
{
    if (move.size() != 4)
        return false;  // Invalid move format
    
    char currentFile = move[0];
    char currentRank = move[1];
    char nextFile = move[2];
    char nextRank = move[3];
    
    // Check if the pawn moved in a straight line and one square ahead
    if (nextRank == currentRank + 1 && nextFile == currentFile)
        return true;
    
    // Check if the pawn moved two squares from its initial position
    if (currentRank == '2' && nextRank == '4' && nextFile == currentFile)
        return true;
    
    // Check if the pawn moved diagonally by capturing a piece
    if ((nextFile == currentFile + 1 || nextFile == currentFile - 1) && nextRank == currentRank + 1)
    {
        std::string captureSquare = move.substr(2);

        // Check if there is a piece on the diagonal square
        for (Piece* piece : blackObjects)
        {
            if (piece->getPieceSquare() == captureSquare)
            {
                piece->destroyTexture();
                return true;
            }
        }
    }
    
    return false;
}



bool Pawn::isBlackPawnMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects)
{
    if (move.size() != 4)
        return false;  // Invalid move format
    
    char currentFile = move[0];
    char currentRank = move[1];
    char nextFile = move[2];
    char nextRank = move[3];
    
    // Convert characters to integers
    int currentFileIndex = currentFile - 'a';
    int currentRankIndex = currentRank - '1';
    int nextFileIndex = nextFile - 'a';
    int nextRankIndex = nextRank - '1';
    
    // Check if the pawn moved in a straight line and one square ahead
    if (nextRankIndex == currentRankIndex - 1 && nextFileIndex == currentFileIndex)
        return true;
    
    // Check if the pawn moved two squares from its initial position
    if (currentRank == '7' && nextRank == '5' && nextFileIndex == currentFileIndex)
        return true;
    
    // Check if the pawn moved diagonally by capturing a piece
    if (nextFileIndex == currentFileIndex + 1 || nextFileIndex == currentFileIndex - 1)
    {
        std::string captureSquare = move.substr(2);

        // Check if there is a piece on the diagonal square
        for (Piece* piece : whiteObjects)
        {
            if (piece->getPieceSquare() == captureSquare)
            {
                piece->destroyTexture();
                return true;
            }
        }
    }
    
    return false;
}





void Pawn::snapToPrev(const std::string& move, Piece* obj) 
{
    // Extract the previous algebraic location from the move string
    std::string prevSquare = move.substr(0, 2);
    
    // Convert the algebraic location to coordinates
    char file = prevSquare[0];
    char rank = prevSquare[1];
    int fileIndex = file - 'a';
    int rankIndex = rank - '1';
    
    // Calculate the previous coordinates of the piece
    int x = 50 + fileIndex * 80;
    int y = 90 + (7 - rankIndex) * 80;

    
    // Snap the piece back to the previous coordinates
    obj->pieceX = x;
    obj->pieceY = y;
    
    // Reset the isPieceClicked flag
    obj->isPieceClicked = false;
}