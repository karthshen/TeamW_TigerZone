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
	// call CheckMeeplePLacement, CheckCompletedCity, and CheckCompletedRoad
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

void Board::CheckCompletedCity(int xPos,int yPos)
{
	//call every time a tile is placed to see if a city is completed for
	// scoring
	
	//DFS or BFS search of all connected city terrains
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples in the city gets the points)
	
	//return meeples and add to score of corresponding player
}

int Board::CountRoad(int xPrev, int yPrev, int xCurr, int yCurr, int xStart, int yStart)
{
	if(board[xCurr][yCurr] == null)		//If no tile placed, road is not complete
	{
		return -1;
	}
	
	if(xCurr == xStart && yCurr == yStart)	//If we are where we started
	{
		return 0;		//return 0 because we have finished a loop with no intersections
	}					//point for this tile will be counted at first function call
	
	
	// bool values for where the current tile is to relation of previous tile
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	
	if(xPrev != xCurr)
	{
		if(xPrev > xCurr) //current tile is to the left of previous tile
		{
			left = true;
		}
		else right = true;
	}
	if(yPrev != yCurr)
	{
		if(yPrev > yCurr) //current tile is above previous tile
		{
			up = true;
		}
		else down = true;
	}
	
	//We already know where the first part of the road is on the
	// current tile which connects to the previous tile, so we check 
	// where the next part of the road is or if it ends at this tile
	if(board[xCurr][yCurr] != 0)	//tile is an end to the road
	{
		return 1;
	}
	else				//otherwise, find where the road continues
	{
		if(board[xCurr][yCurr].getN() == 3 && !down)	//don't want this road if previous tile is above
		{
			if(CountRoad(xCurr, yCurr, xCurr, yCurr-1, xStart, yStart) == -1)
			{		//if road doesn't connect to a tile, then road is not complete
				return -1;		//return -1 all the way back to the beginning function call
			}
			else return 1 + CountRoad(xCurr, yCurr, xCurr, yCurr-1, xStart, yStart);
			
		}
		if(board[xCurr][yCurr].getS() == 3 && !up)
		{
			if(CountRoad(xCurr, yCurr, xCurr, yCurr+1, xStart, yStart) == -1
			{
				return -1;
			}
			else return 1 + CountRoad(xCurr, yCurr, xCurr, yCurr+1, xStart, yStart);
		}
		if(board[xCurr][yCurr].getE() == 3 && !left)
		{
			if(CountRoad(xCurr, yCurr, xCurr+, yCurr, xStart, yStart) == -1)
			{
				return -1;
			}
			else return 1 + CountRoad(xCurr, yCurr, xCurr+, yCurr, xStart, yStart);
		}
		if(board[xCurr][yCurr].getW() == 3 && !right)
		{
			if(CountRoad(xCurr, yCurr, xCurr-1, yCurr xStart, yStart) == -1)
			{
				return -1;
			}
			else return 1 + CountRoad(xCurr, yCurr, xCurr-1, yCurr, xStart, yStart);
		}
	}
			
}

void Board::CheckCompletedRoad(int xPos, int yPos)
{
	Tile tile = board[xPos][yPos];
	int pointsN = 0;
	int pointsS = 0;
	int pointsE = 0;
	int pointsW = 0;
	
	
	//Call every time a tile is placed to see if a road is completed for
	// scoring
	
	bool roadN = false;
	bool roadS = false;
	bool roadE = false;
	bool roadW = false;
	int roadCount = 0;
	//Check for any roads on the tile
	if(tile.getN() == 3)
	{
		roadN = true;
		++roadCount;
	}
	if(tile.getS() == 3)
	{
		roadS = true;
		++roadCount;
	}
	if(tile.getE() == 3)
	{
		roadE = true;
		++roadCount;
	}
	if(tile.getW() == 3)
	{
		roadW = true;
		++roadCount;
	}
	
	//Check there are any roads on tile
	if(roadCount == 0)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < roadcount; ++i)	//search in every direction for completed road
		{									//can be up to 4 roads from an intersection
											//and 2 if starting from the middle of the road
			if(roadN)
			{
				pointsN = 1 + CountRoad(xPos, yPos, xPos, yPos-1, xPos, yPos);
				roadN = false;		//set to false so next loop iteration doesn't
									//just redo the search in this direction
			}
			if(roadS)
			{
				pointsS = 1 + CountRoad(xPos, yPos, xPos, yPos+1, xPos, yPos);
				roadS = false;
			}
			if(roadE)
			{
				pointsE = 1 + CountRoad(xPos+1, yPos, xPos, yPos, xPos, yPos);
				roadE = false;
			}
			if(roadW)
			{
				pointsW = 1 + CountRoad(xPos-1, yPos, xPos, yPos, xPos, yPos);
				roadW = false;
			}
		}
		
		if(tile.center != 0)	//check if center of tile is an end of a road
		{					//check for any completed roads (all would be separate)
			if(pointsN != 0)
			{
				//Need a function to settle meeple displutes
				// and to return which player(s) recieve the points
				
				//Player.score += pointsN
				//Player.returnMeeple
			}
			if(pointsS != 0)
			{
				
			}
			if(pointsE != 0)
			{
				
			}
			if(pointsW != 0)
			{
				
			}
			
		}
		else		//if road doesnt end in center, there must only be 2 roads
		{			//and we are in the middle of the road. Add scores into 1
			int points == 0;
			if(pointsN != 0)
			{
				//Need a function to settle meeple displutes
				// and to return which player(s) recieve the points
				points += pointsN;
			}
			if(pointsS != 0)
			{
				points += pointsS;
			}
			if(pointsE != 0)
			{
				points += pointsE;
			}
			if(pointsW != 0)
			{
				points += pointsE;
			}
			
			if(points != 0)
			{
				//player.score += points
				//player.ReturnMeeple?

			}
		}
	}
	
	//settle any meeple disputes (if there are meeples from multiple players,
	// the player with more meeples on the road gets the points)
	
	//return meeples and add to score for corresponding player
}

void Board::CheckSurroundedBuilding(int xPos, int yPos)
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

