#include <iostream>

#include "Tile.h"
#include "Players.h"
#include "Gamebase.h"

using namespace std;

class Board
{
private:
	Tile deck[72];
	Tile* board;
	Tile startTile;

	int PlaceStartTile();
	int CheckTilePlacement(const Tile& tile, int xPos, int yPos);
	int CheckMeeplePlacement(int xPos, int yPos, String meepleStr);
	int CheckCompletedCity(xPos,yPos);
	int CheckCompletedRoad(xPos, yPos);
	int CheckCompletedDen(xPos, yPos);
	
public:

	Board();
	~Board();

    int DisplayBoard();
	int PlaceTile(const Tile& tile, int xPos, int yPos);
	int CheckAvailibleSpots(const Tile& tile);
	int ShowAvailibleMeepleSpots();
	int CountEndGameScore(int playerNumber);
	
	
	int MakeDeck();
	
};
