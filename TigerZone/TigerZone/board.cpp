#include "Board.h"


using namespace std;



Board::Board()
{
	for(int i = 0; i<143;i++)
	{
		for (int j = 0; j<143; j++)
		{
			board[i][j] = NULL;
		}
	}
}

Board::~Board()
{
	delete board;
	delete deck;
}

void Board::PlaceStartTile()
{
	// place the starting tile in the middle of the board
	//board[71][71] = startingTileType;
}

void Board::PlaceTile(int x, int y, int r)
{
	//Place the tile with x and y coordinate. R for the number
}

void Board::PlaceMeaple(); //
{
	
}
int Board::CheckTilePlacement(const Tile& tile, int xPos, int yPos)
{
	//used to verify tile placement (for initial testing)
	//could also make a bool method
	if(board[xPos][yPos] != null)
	{
		cout<<"Location already picked"<<endl;
		return 0;
	}
	
	//check if tile is adjacent to another
	bool isAdjacent = false;
	bool nAdjacent =false;
	bool sAdjacent = false;
	bool wAdjacent = false;
	bool eAdjacent = false;
	if(board[xPos-1][yPos]!=NULL)
	{
		isAdjacent = true;
		wAdjacent = true;
	}
	if(board[xPos+1][yPos]!=NULL)
	{
		isAdjacent = true;
		eAdjacent = true;
	}
	if(board[xPos][yPos+1]!=NULL)
	{
		isAdjacent = true;
		nAdjacent = true;
	}
	if(board[xPos][yPos-1]!=NULL)
	{
		isAdjacent = true;
		sAdjacent = true;
	}
	
	if(!isAdjacent)
		return 0;
	//check if sides match up to adjacent sides
	if(nAdjacent)
	{
		if(board[xPos][yPos+1]->sideS != tile->sideN)
			return 0;
	}
	
	if(sAdjacent)
	{
		if(board[xPos][yPos-1]->sideN != tile->sideS)
			return 0;
	}
	
	if(wAdjacent)
	{
		if(board[xPos-1][yPos]->sideE != tile->sideW)
			return 0;
	}
	
	if(eAdjacent)
	{
		if(board[xPos+1][yPos]->sideW != tile->sideE)
			return 0;
	}
	
	board[xPos][yPos] = tile;
	return 1;
}

void Board::CheckMeeplePlacement(const Tile& tile, xPos, yPos, meepleSpot)
{
	//used to verify meeple placement (for initial testing)
	//need a way to check all connected parts of tiles that are the same
	// terrain as the proposed meepleSpot
}

void Board::CheckCompletedCity(xPos,yPos)
{
	//call every time a tile is placed to see if a city is completed for
	// scoring
	
	//DFS or BFS search of all connected city terrains
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples in the city gets the points)
	
	//return meeples and add to score of corresponding player
}

void Board::CheckCompletedRoad(xPos, yPos)
{
	//Call every time a tile is placed to see if a road is completed for
	// scoring
	
	//DFS or BFS search of all connected terrains with a road
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples on the road gets the points)
	
	//return meeples and add to score for corresponding player
}

void Board::CheckSurroundedBuilding(xPos, yPos)
{
	//check if there are any buildings within one spot of the newly placed
	// tile
	
	//check to see if the building has a meeple on it
	
	//check to see if the building is completely surrounded
	// if so, return the meeple and add points for the owner of the meeple.
}




void Board::DisplayBoard()
{
	//call to update the board in the UI whenever a change occurs
	// such as tile or meeple placement
}

void Board::PlaceTile(const Tile& tile, int xPos, int yPos)
{
	CheckTilePlacement(tile, xPos, yPos);
	//board[x][y] = tile;
	
	CheckCompletedCity(xPos, yPos);
	CheckCompletedRoad(xPos, yPos);
	CheckSurroundedBuilding(xPos,yPos);
}

//function to show possible spots for a given tile
// can be moved to AI class later
void Board::CheckAvailibleSpots(const Tile& tile)
{
	//gather information about the sides of the tile
	topSide = tile.topSide;
	bottomSide = tile.bottomSide;
	rightSide = tile.rightSide;
	leftSide = tile.leftSide;
	
	//DFS or BFS search for availible spots
	
	//check if no spots are availible, want to send request to
	// another class to remove the tile from the game
	if(availibleSpots.length() == 0)
	{
		//throw tile away and get a new one
	}
	
	//can make this function return matrix positions
	// of availible spots
	
}

void Board::ShowAvailibleMeepleSpots()
{
	//want to return possible meeple places for after a tile is placed.
	//This can be moved to the AI class later as well
}


int Board::CountEndGameScore(int playerNumber)
{
	//Count all points from the meeples belonging to the specified player
	
	//all unfinished cities
	//all unfinished roads
	//all farmers (in the fields)
	// settle any meeple disputes (meeples from both players)
	//all unfinished field buildings
}




int Board::MakeDeck()
{
/* 
 * Value for sideX: 
 * 			0. Empty
 * 			1. Field
 * 			2. Town
 * 			3. Field with Road
 * Value for center:
 * 			0. Empty
 * 			1. Field
 * 			2. House
 * 			3. Crossroad
 * 			4. Church
*/

	//shield: 1 = true, 0 = false	
	
	deck[1] 	= new tile(2,3,3,2,2,0);
	deck[2] 	= new tile(2,3,3,2,2,0);
	deck[3] 	= new tile(2,3,3,2,2,0);
	
	deck[4] 	= new tile(2,2,1,2,2,1);
	deck[5] 	= new tile(2,2,1,2,2,1);
	deck[6] 	= new tile(2,2,1,2,2,1);
	deck[7] 	= new tile(2,2,1,2,2,1);
	
	deck[8] 	= new tile(2,1,1,2,2,1);
	deck[9] 	= new tile(2,1,1,2,2,1);
	deck[10-12] 	= new tile(2,1,1,2,2,0);
	deck[13-14] 	= new tile(2,3,3,2,2,1);
	deck[15-23] 	= new tile(1,1,3,3,1,0);
	deck[24-27] 	= new tile(1,3,3,3,3,0);
	deck[28] 	= new tile(3,3,3,3,3,0);
	deck[29-30] 	= new tile(2,2,3,2,2,1);
	deck[31] 	= new tile(2,2,3,2,2,0);
	deck[32-39] 	= new tile(1,3,1,3,1,0);
	deck[40-42] 	= new tile(2,3,3,3,3,0);
	deck[43] 	= new tile(2,2,2,2,2,1);
	deck[44-47] 	= new tile(2,3,1,3,1,0);
	deck[48-52] 	= new tile(2,1,1,1,1,0);
	deck[53-54] 	= new tile(1,1,3,1,4,0);
	deck[55-58] 	= new tile(1,1,1,1,4,0);
	deck[59-60] 	= new tile(2,1,1,2,1,0);
	deck[61-63] 	= new tile(2,3,3,1,1,0);
	deck[64-66] 	= new tile(2,1,3,3,1,0);
	deck[67-68] 	= new tile(1,2,2,1,2,1);
	deck[69] 	= tile(1,2,2,1,2,0);
	deck[70-72] 	= tile(1,2,2,1,1,0);
}

