#include <iostream>

class Player {

private:

	Tile tileStack[36]; //initialization of this should be done by the game initialization
    Tile currentTile; //tile object or class
	Meeple meeples//[??]

	
	// places current tile at location specified by x,y with r rotations
	void placeTile(int x int y int r) {
		Board::PlaceTile(x, y, r)
	}
	
	void placeMeeple(meeple, board) {
		//board.location = meeple;
	}

public:
	bool isHuman;
	int	score;

};