//#include "tiles.h"
//#include "board.h"
//#include "players.h"
#pragma once
#include <iostream>


#include "board.h"
#include "player.h"
#include "Tile.h"


class Gamebase
{
public:
	Gamebase();
	Gamebase(Board* b, Player* p1, Player* p2);
	~Gamebase();

	bool Run();
	

	bool start;
	bool exit;

	bool end;

private:
	//PlayerLogics
	//AddTiles
	//etc

	bool isGameEnded();
	
	Board* board;
	Player* player1;
	Player* player2;
	








};
