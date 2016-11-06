#include <iostream>

class Player {

private:

	Tile tileStack[36]; //initialization of this should be done by the game initialization
    Tile currentTile; //tile object or class
	Meeple meepls//[??]

	void placeTile(tile, board) {
		//board.location = tile;
	}
	
	void placeMeeple(meeple, board) {
		//board.location = meeple;
	}

public:
	bool isHuman;
	int	score;

};