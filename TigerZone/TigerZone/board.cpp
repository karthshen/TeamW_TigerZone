#include "Board.h"
#include <queue>

// return value: 1=success
int Board::PlaceStartTile()
{
	// place the starting tile in the middle of the board
	// start tile initialized in Board constructor
	board[71][71] = startTile;
	return 1;
}

// return value: 0=invalid tile placement
// 				 1=valid tile placement
int Board::CheckTilePlacement(const Tile& tile, int xPos, int yPos)
{
	//used to verify tile placement (for initial testing)
	//could also make a bool method
	if(board[xPos][yPos] != null)
	{
		throw;
	}
	//check if tile is adjacent to another
	//check if sides match up to adjacent sides
}

// return value: 0=invalid meeple placement
// 				 1=valid meeple placement
int Board::CheckMeeplePlacement(int xPos, int yPos, String meepleSpot)
{
	// get the meeple placement
	int meapleN = 0;
	int meapleS = 0;
	int meapleW = 0;
	int meapleE = 0;
	switch(meepleSpot){
		case "N":
			meapleN = 2;
			break;
		case "S":
			meapleS = 2;
			break;
		case "W":
			meapleW = 2;
			break;
		case "E":
			meapleE = 2;
			break;
		case "NE":
			meapleN = 3;
			meapleE = 1;
			break;
		case "NW":
			meapleN = 1;
			meapleW = 3;
			break;
		case "SE":
			meapleS = 1;
			meapleE = 3;
			break;
		case "SW":
			meapleS = 3;
			meapleW = 1;
			break;
		default:
			return 0; // return false, input error
			break;
	}

	// // array to check if tile has been visited
	// // values: 0=no tile; 
	// // 		   1=tile present, not visited
	// // 		   2=tile present, visited
	// int visited[143][143];

	// // check if tiles are present at each board spot
	// for(int i=0; i<143; i++){
	// 	for(int j=0; j<143; j++){
	// 		if(board[i][j] != NULL)
	// 			visited[i][j] = 1; // tile present
	// 	}
	// }
}

// return value: 0=no newly completed cities
// 				 !0=number of points awarded for newly completed city
int Board::CheckCompletedCity(xPos,yPos)
{
	//call every time a tile is placed to see if a city is completed for
	// scoring
	
	//DFS or BFS search of all connected city terrains
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples in the city gets the points)
	
	//return meeples and add to score of corresponding player
}

// return value: 0=no newly completed roads
// 				 !0=number of points awarded for newly completed roads
int Board::CheckCompletedRoad(xPos, yPos)
{
	//Call every time a tile is placed to see if a road is completed for
	// scoring
	
	//DFS or BFS search of all connected terrains with a road
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples on the road gets the points)
	
	//return meeples and add to score for corresponding player
}

// return value: 0=no newly completed dens
// 				 !0=number of points awarded for newly completed dens
int Board::CheckCompletedDen(xPos, yPos)
{
	//check if there are any buildings within one spot of the newly placed
	// tile
	
	//check to see if the building has a meeple on it
	
	//check to see if the building is completely surrounded
	// if so, return the meeple and add points for the owner of the meeple.
}

// constructor
Board::Board()
{
	Tile* board[143][143];
	this->board = board;
	startTile = new Tile(2, 3, 1, 3, 3, 0);
}

// destructor
Board::~Board()
{
	
}

int Board::DisplayBoard()
{
	//call to update the board in the UI whenever a change occurs
	// such as tile or meeple placement
}

// return value: 0=invalid tile placement
// 				 1=successful tile placement
int Board::PlaceTile(const Tile& tile, int xPos, int yPos)
{
	// if tile placement is illegal, return 0
	if(CheckTilePlacement(tile, xPos, yPos)==0)
		return 0;
	// if tile placement is legal, place tile at position
	board[xPos][yPos] = tile;
	
	// check is city is completed
	int pts = CheckCompletedCity(xPos, yPos);
	if(pts != 0)
		// add up points
	// check if road is completed
	pts = CheckCompletedDen(xPos,yPos);
	if(pts != 0)
		// add up points
	return 1; // success
}


//function to show possible spots for a given tile
// can be moved to AI class later
int Board::CheckAvailibleSpots(const Tile& tile)
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

int Board::ShowAvailibleMeepleSpots()
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
	
	deck[1-3] 	= new Tile(2,3,3,2,2,0);
	deck[4] 	= new Tile(2,2,1,2,2,1);
	deck[5-7] 	= new Tile(2,2,1,2,2,1);
	deck[8-9] 	= new Tile(2,1,1,2,2,1);
	deck[10-12] 	= new Tile(2,1,1,2,2,0);
	deck[13-14] 	= new Tile(2,3,3,2,2,1);
	deck[15-23] 	= new Tile(1,1,3,3,1,0);
	deck[24-27] 	= new Tile(1,3,3,3,3,0);
	deck[28] 	= new Tile(3,3,3,3,3,0);
	deck[29-30] 	= new Tile(2,2,3,2,2,1);
	deck[31] 	= new Tile(2,2,3,2,2,0);
	deck[32-39] 	= new Tile(1,3,1,3,1,0);
	deck[40-42] 	= new Tile(2,3,3,3,3,0);
	deck[43] 	= new Tile(2,2,2,2,2,1);
	deck[44-47] 	= new Tile(2,3,1,3,1,0);
	deck[48-52] 	= new Tile(2,1,1,1,1,0);
	deck[53-54] 	= new Tile(1,1,3,1,4,0);
	deck[55-58] 	= new Tile(1,1,1,1,4,0);
	deck[59-60] 	= new Tile(2,1,1,2,1,0);
	deck[61-63] 	= new Tile(2,3,3,1,1,0);
	deck[64-66] 	= new Tile(2,1,3,3,1,0);
	deck[67-68] 	= new Tile(1,2,2,1,2,1);
	deck[69] 	= Tile(1,2,2,1,2,0);
	deck[70-72] 	= Tile(1,2,2,1,1,0);
}

