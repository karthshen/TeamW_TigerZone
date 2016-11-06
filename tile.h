#include <iostream>

class tile {

	private:
		//Tile components
		int up;
		int right;
		int down;
		int left;
		int cent;
		bool farm;
		int shield;

	public:
		//Basic methods
		tile();
		tile(int up, int right, int down, int left, int cent, int shield);
		void rotate();
};

tile::tile(){
	this->up = NULL;
	this->right = NULL;
	this->down = NULL;
	this->left = NULL;
	this->cent = NULL;
	this->farm = NULL;
	this->shield = NULL;
}

tile::tile(int up, int right, int down, int left, int cent, int shield){
	this->up = up;
	this->right = right;
	this->down = down;
	this->left = left;
	this->cent = cent;
	this->farm = false;
	this->shield = shield;
}

void tile::rotate(){
	int temp = up;
	this->up = right;
	this->right = down;
	this->down = left;
	this->left = temp;

class board {

public:
	stack startdeck();
};


stack board::makedeck(){
//side: field = 1, town = 2, field with road = 3
//cent: field = 1, connected town = 2, crossroad = 3, monastery = 4
//shield: 1 = true, 0 = false	
	tile deck[72];
	deck[1-3] 	= tile(2,3,3,2,2,0);
	deck[4] 	= tile(2,2,1,2,2,1);
	deck[5-7] 	= tile(2,2,1,2,2,1);
	deck[8-9] 	= tile(2,1,1,2,2,1);
	deck[10-12] 	= tile(2,1,1,2,2,0);
	deck[13-14] 	= tile(2,3,3,2,2,1);
	deck[15-23] 	= tile(1,1,3,3,1,0);
	deck[24-27] 	= tile(1,3,3,3,3,0);
	deck[28] 	= tile(3,3,3,3,3,0);
	deck[29-30] 	= tile(2,2,3,2,2,1);
	deck[31] 	= tile(2,2,3,2,2,0);
	deck[32-39] 	= tile(1,3,1,3,1,0);
	deck[40-42] 	= tile(2,3,3,3,3,0);
	deck[43] 	= tile(2,2,2,2,2,1);
	deck[44-47] 	= tile(2,3,1,3,1,0);
	deck[48-52] 	= tile(2,1,1,1,1,0);
	deck[53-54] 	= tile(1,1,3,1,4,0);
	deck[55-58] 	= tile(1,1,1,1,4,0);
	deck[59-60] 	= tile(2,1,1,2,1,0);
	deck[61-63] 	= tile(2,3,3,1,1,0);
	deck[64-66] 	= tile(2,1,3,3,1,0);
	deck[67-68] 	= tile(1,2,2,1,2,1);
	deck[69] 	= tile(1,2,2,1,2,0);
	deck[70-72] 	= tile(1,2,2,1,1,0);	
}