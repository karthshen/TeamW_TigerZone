#include <iostream>
#include "Board.h"

class Player {

private:

	

	Tile tileStack[36]; //initialization of this should be done by the game initialization
    Tile currentTile; //tile object or class
	Meeple meeples//[??]

	
	// places current tile at location specified by x,y with r rotations
	void placeTile(const Tile& tile, int x, int y);
	}
	
	void placeMeeple(const Meeple& meeple, int x, int y);

public:
	Player();
	~Player();
	bool isHuman;
	int	score;	

};