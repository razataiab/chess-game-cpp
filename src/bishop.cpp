#include "bishop.h"
#include <vector>


bool Bishop::isWhiteBishopMoveLegal(std::string move, const std::vector<Piece*>& blackObjects)
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
    
    // Check if the bishop moves diagonally to a legal square
    if (absFileDiff == absRankDiff)
    {
        // Calculate the direction of movement
        int fileDirection = (fileDiff > 0) ? 1 : -1;
        int rankDirection = (rankDiff > 0) ? 1 : -1;
        
        // Check if the next square is a legal diagonal square
        int file = currentFileIndex + fileDirection;
        int rank = currentRankIndex + rankDirection;
        
        // Check the left diagonal squares
        while (file != nextFileIndex && rank != nextRankIndex)
        {
            // Convert the file and rank to algebraic notation
            char fileChar = 'a' + file;
            char rankChar = '1' + rank;
            
            // Check if the diagonal square is a legal move
            if (fileChar >= 'a' && fileChar <= 'h' && rankChar >= '1' && rankChar <= '8')
            {
                std::string diagonalSquare = std::string(1, fileChar) + std::string(1, rankChar);
                // You can perform any additional logic here if needed for capturing or blocking
                
                // Check if there is a piece on the diagonal square
                for (Piece* piece : blackObjects)
                {
                    if (piece->getPieceSquare() == diagonalSquare)
                    {
                        // Capture the piece if needed
                        break;
                    }
                }
            }
            
            // Move to the next diagonal square
            file += fileDirection;
            rank += rankDirection;
        }
        
        return true;
    }
    
    return false;
}





bool Bishop::isBlackBishopMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects)
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
    
    // Check if the bishop moves diagonally to a legal square
    if (absFileDiff == absRankDiff)
    {
        // Calculate the direction of movement
        int fileDirection = (fileDiff > 0) ? 1 : -1;
        int rankDirection = (rankDiff > 0) ? 1 : -1;
        
        // Check if the next square is a legal diagonal square
        int file = currentFileIndex + fileDirection;
        int rank = currentRankIndex + rankDirection;
        
        // Check the left diagonal squares
        while (file != nextFileIndex && rank != nextRankIndex)
        {
            // Convert the file and rank to algebraic notation
            char fileChar = 'a' + file;
            char rankChar = '1' + rank;
            
            // Check if the diagonal square is a legal move
            if (fileChar >= 'a' && fileChar <= 'h' && rankChar >= '1' && rankChar <= '8')
            {
                std::string diagonalSquare = std::string(1, fileChar) + std::string(1, rankChar);
                // You can perform any additional logic here if needed for capturing or blocking
                
                // Check if there is a piece on the diagonal square
                for (Piece* piece : whiteObjects)
                {
                    if (piece->getPieceSquare() == diagonalSquare)
                    {
                        // Capture the piece if needed
                        break;
                    }
                }
            }
            
            // Move to the next diagonal square
            file += fileDirection;
            rank += rankDirection;
        }
        
        return true;
    }
    
    return false;
}




void Bishop::snapToPrev(const std::string& move, Piece* obj) 
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