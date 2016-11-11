#include "Player.h"

using namespace std;

Player::Player(){
	isHuman = 1; //this must be changed in the future
	
}
Player::~Player() {
	 
	
}

// places current tile at location specified by x,y
void placeTile(const Tile& tile, int x, int y) {
		//calls board class's PlaceTile function
		Board::PlaceTile(tile, x, y);
}
	
void placeMeeple(const Meeple& meeple, int x, int y) {
	//needs meeple class working first
}

