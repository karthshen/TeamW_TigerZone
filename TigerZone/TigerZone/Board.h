#include <iostream>
//#include classes

using namespace std;

class GameBoard
{
    Tile* board[143][143];
    
    // place the starting tile in the middle of the board
	void PlaceStartTile()
	{
	    //board[71][71] = startingTileType;
	}
	
	//used to verify tile placement (for initial testing)
	void CheckTilePlacement(const Tile& tile, int xPos, int yPos)
	{
	    //could also make a bool method
	    if(board[xPos][yPos] != null)
	    {
	        throw;
	    }
	    //check if tile is adjacent to another
	    //check if sides match up to adjacent sides
	}
	
	//used to verify meeple placement (for initial testing)
	void CheckMeeplePlacement(const Tile& tile, xPos, yPos, meepleSpot)
	{
	    //need a way to check all connected parts of tiles that are the same
	    // terrain as the proposed meepleSpot
	}
	
	void CheckCompletedCity(xPos,yPos)
	{
	    //call every time a tile is placed to see if a city is completed for
	    // scoring
	    
	    //DFS or BFS search of all connected city terrains
	    
	    //settle any meeple disputes (if there are meeples from multiple players,
	    // the player with more meeples in the city gets the points)
	    
	    //return meeples and add to score of corresponding player
	}
	
	void CheckCompletedRoad(xPos, yPos)
	{
	    //Call every time a tile is placed to see if a road is completed for
	    // scoring
	    
	    //DFS or BFS search of all connected terrains with a road
	    
	    //settle any meeple disputes (if there are meeples from multiple players,
	    // the player with more meeples on the road gets the points)
	    
	    //return meeples and add to score for corresponding player
	}
	
	void CheckSurroundedBuilding(xPos, yPos)
	{
	    //check if there are any buildings within one spot of the newly placed
	    // tile
	    
	    //check to see if the building has a meeple on it
	    
	    //check to see if the building is completely surrounded
	    // if so, return the meeple and add points for the owner of the meeple.
	}
	
	
	
	public:

    void DisplayBoard()
    {
        //call to update the board in the UI whenever a change occurs
        // such as tile or meeple placement
    }
    
	void PlaceTile(const Tile& tile, int xPos, int yPos)
	{
	    CheckTilePlacement(tile, xPos, yPos);
	    //board[x][y] = tile;
	    
	    CheckCompletedCity(xPos, yPos);
	    CheckCompletedRoad(xPos, yPos);
	    CheckSurroundedBuilding(xPos,yPos);
	}
	
	//function to show possible spots for a given tile
	// can be moved to AI class later
	void CheckAvailibleSpots(const Tile& tile)
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
	
	void ShowAvailibleMeepleSpots()
	{
	    //want to return possible meeple places for after a tile is placed.
	    //This can be moved to the AI class later as well
	}
	
	
	int CountEndGameScore(int playerNumber)
	{
	    //Count all points from the meeples belonging to the specified player
	    
	    //all unfinished cities
	    //all unfinished roads
	    //all farmers (in the fields)
	    // settle any meeple disputes (meeples from both players)
	    //all unfinished field buildings
	}
	
}

