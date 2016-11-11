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



struct coordinate{
	int x;
	int y;
};

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

	// starting tile
	Tile* root = board[xPos][yPos];
	// get the terrain type
	int terrainType = 0;
	if(meapleN != 0){
		terrainType = root.sideN;
	}
	else if(meapleS != 0){
		terrainType = root.sideS;
	}
	else if(meapleW != 0){
		terrainType = root.sideW;
	}
	else if(meapleE != 0){
		terrainType = root.sideE;
	}

	// queue of coordinates for BFS
	queue<coordinate> Q;
	
	if(meapleN != 0 || (center == terrainType && root.sideN == terrainType)){
		if(board[xPos][yPos+1] != NULL){
			Tile* adjacent = board[xPos][yPos+1];
			if(adjacent.sideS == terrainType){
				if(adjacent.meapleS != 0){
					return 0;
				}
				else{
					struct coordinate c;
					c.x = xPos;
					c.y = yPos+1;
					Q.push(c);
				}
			}
		}
	}
	if(meapleS != 0 || (center == terrainType && root.sideS == terrainType)){
		if(board[xPos][yPos-1] != NULL){
			Tile* adjacent = board[xPos][yPos-1];
			if(adjacent.sideN == terrainType){
				if(adjacent.meapleN != 0){
					return 0;
				}
				else{
					struct coordinate c;
					c.x = xPos;
					c.y = yPos-1;
					Q.push(c);
				}
			}
		}
	}
	if(meapleW != 0 || (center == terrainType && root.sideW == terrainType)){
		if(board[xPos-1][yPos] != NULL){
			Tile* adjacent = board[xPos-1][yPos];
			if(adjacent.sideE == terrainType){
				if(adjacent.meapleE != 0){
					return 0;
				}
				else{
					struct coordinate c;
					c.x = xPos-1;
					c.y = yPos;
					Q.push(c);
				}
			}
		}
	}
	if(meapleE != 0 || (center == terrainType && root.sideE == terrainType)){
		if(board[xPos+1][yPos] != NULL){
			Tile* adjacent = board[xPos+1][yPos];
			if(adjacent.sideW == terrainType){
				if(adjacent.meapleW != 0){
					return 0;
				}
				else{
					struct coordinate c;
					c.x = xPos+1;
					c.y = yPos;
					Q.push(c);
				}
			}
		}
	}

	while(!Q.empty()){
		struct coordinate c = Q.pop();
		Tile* current = board[c.x][c.y];
		// if the search cycles back to the root
		if(current == root)
			return 1;
		if(current.center == terrainType){
			if(current.sideN == terrainType){
				if(current.meapleN != 0){
					return 0;
				}
				if(board[xPos][yPos+1] != NULL){
					Tile* adjacent = board[xPos][yPos+1];
					else if(adjacent.sideS == terrainType){
						if(adjacent.meapleS != 0){
							return 0;
						}
						else{
							struct coordinate c;
							c.x = xPos;
							c.y = yPos+1;
							Q.push(c);
						}
					}
				}
			}
			if(current.sideS == terrainType){
				if(current.meapleS != 0){
					return 0;
				}
				if(board[xPos][yPos-1] != NULL){
					Tile* adjacent = board[xPos][yPos-1];
					else if(adjacent.sideN == terrainType){
						if(adjacent.meapleN != 0){
							return 0;
						}
						else{
							struct coordinate c;
							c.x = xPos;
							c.y = yPos-1;
							Q.push(c);
						}
					}
				}
			}
			if(current.sideW == terrainType){
				if(current.meapleW != 0){
					return 0;
				}
				if(board[xPos-1][yPos] != NULL){
					Tile* adjacent = board[xPos-1][yPos];
					else if(adjacent.sideE == terrainType){
						if(adjacent.meapleE != 0){
							return 0;
						}
						else{
							struct coordinate c;
							c.x = xPos-1;
							c.y = yPos;
							Q.push(c);
						}
					}
				}
			}
			if(current.sideE == terrainType){
				if(current.meapleE != 0){
					return 0;
				}
				if(board[xPos+1][yPos] != NULL){
					Tile* adjacent = board[xPos+1][yPos];
					else if(adjacent.sideW == terrainType){
						if(adjacent.meapleW != 0){
							return 0;
						}
						else{
							struct coordinate c;
							c.x = xPos+1;
							c.y = yPos;
							Q.push(c);
						}
					}
				}
			}
		}
	}
	
	// if function has not returned by now, meeple may be placed
	// place meeple
	root.PlaceMeaple(meepleSpot);

	return 1;
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

