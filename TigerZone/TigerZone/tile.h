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
 *			4. Center
 * 
*/
class Tile {
private:
	/*North*/
	int sideN;
	
	/*East*/
	int sideE;

	/*South*/
	int sideS;

	/*West*/
	int sideW;

	/*Center*/
	int center;
	
	bool farm; //Farm for the meaple
	int shield; //If shield is present


	//Meaple Locations
	/*North*/
	int meapleN;
	
	/*East*/
	int meapleE;

	/*South*/
	int meapleS;

	/*West*/
	int meapleW;

public:
	
	Tile();
	~Tile();
	Tile(int north, int east, int south, int west, int center, int shield);


	int Rotate90(); //Roate the tile by 90 degrees anti-clockwise
	int PlaceMeaple(string str); // place meaple on board

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
	int getMeapleNW();
	int getMeapleNE();
	int getMeapleSW();
	int getMeapleSE();
};
