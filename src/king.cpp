#include "king.h"
#include <vector>

bool King::isWhiteKingMoveLegal(std::string move, const std::vector<Piece*>& blackObjects)
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
    
    // Calculate the file and rank differences
    int fileDiff = nextFileIndex - currentFileIndex;
    int rankDiff = nextRankIndex - currentRankIndex;
    
    // Calculate the absolute differences
    int absFileDiff = abs(fileDiff);
    int absRankDiff = abs(rankDiff);
    
    // Check if the white king moved one square in any direction
    if (absFileDiff <= 1 && absRankDiff <= 1)
    {
        std::string captureSquare = move.substr(2);

        // Check if there is a black piece on the capture square
        for (Piece* piece : blackObjects)
        {
            if (piece->getPieceSquare() == captureSquare)
            {
                piece->destroyTexture();
                break;  // Piece captured, no need to continue checking
            }
        }

        return true;
    }
    
    return false;
}

bool King::isBlackKingMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects)
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
    
    // Calculate the file and rank differences
    int fileDiff = nextFileIndex - currentFileIndex;
    int rankDiff = nextRankIndex - currentRankIndex;
    
    // Calculate the absolute differences
    int absFileDiff = abs(fileDiff);
    int absRankDiff = abs(rankDiff);
    
    // Check if the black king moved one square in any direction
    if (absFileDiff <= 1 && absRankDiff <= 1)
    {
        std::string captureSquare = move.substr(2);

        // Check if there is a white piece on the capture square
        for (Piece* piece : whiteObjects)
        {
            if (piece->getPieceSquare() == captureSquare)
            {
                piece->destroyTexture();
                break;  // Piece captured, no need to continue checking
            }
        }

        return true;
    }
    
    return false;
}

void King::snapToPrev(const std::string& move, Piece* obj) 
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
