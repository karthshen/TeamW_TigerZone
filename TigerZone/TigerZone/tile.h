#include <iostream>

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
 * Meaple Locations
 * 		Definition of Location: 1 is front left, 2 is center, 3 is front right.
 * 			
 * 			0. No Meaple
 * 			1. Location 1
 * 			2. Location 2
 * 			3. Location 3
 * 
*/
class Tile {
private:
	/*North*/
	int sideN; //Values Possible 1 Field 2 Town 3 Field with Road 
	
	/*East*/
	int sideE;

	/*South*/
	int sideS;

	/*West*/
	int sideW;

	int center; //Values 0. Empty, 1. Field, 2. House 3. CrossRoad 4. Church
	//maybe create a side class but unnessary unless we want to 
	
	bool farm; //Farm for the meatballs
	int shield; //If shield is present


	//Meaple Locations
	int meapleN;
	int meapleS;
	int meapleE;
	int meapleW;

public:
	
	Tile();
	~Tile();
	Tile(int north, int east, int south, int west, int center, int shield);


	void Rotate90(); //Roate the tile by 90 degrees anti-clockwise
	void PlaceMeaple(string str);

	//Tile Side Values
	int getN();
	int getE();
	int getS();
	int getW();
	
	//Get Meaple Locations
	int getMeapleN();
	int getMeapleS();
	int getMeapleE();
	int getMeapleW();

};
