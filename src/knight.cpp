#include "knight.h"
#include <vector>


bool Knight::isWhiteKnightMoveLegal(std::string move, const std::vector<Piece*>& blackObjects)
{
    if (move.size() != 4)
        return false;  // Invalid move format
    
    // char currentFile = move[0];
    // char currentRank = move[1];
    // char nextFile = move[2];
    // char nextRank = move[3];
    
    // // Convert characters to integers
    // int currentFileIndex = currentFile - 'a';
    // int currentRankIndex = currentRank - '1';
    // int nextFileIndex = nextFile - 'a';
    // int nextRankIndex = nextRank - '1';

    // Logic for white Knight's movement
    
    return true;
}



bool Knight::isBlackKnightMoveLegal(std::string move, const std::vector<Piece*>& whiteObjects)
{
    if (move.size() != 4)
        return false;  // Invalid move format
    
    // char currentFile = move[0];
    // char currentRank = move[1];
    // char nextFile = move[2];
    // char nextRank = move[3];
    
    // // Convert characters to integers
    // int currentFileIndex = currentFile - 'a';
    // int currentRankIndex = currentRank - '1';
    // int nextFileIndex = nextFile - 'a';
    // int nextRankIndex = nextRank - '1';

    // Logic for black Knight's movement
    
    return true;
}




void Knight::snapToPrev(const std::string& move, Piece* obj) 
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