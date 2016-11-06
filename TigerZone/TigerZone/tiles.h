#include <iostream>

class Tile {
private:
	/*North*/
	int sideN; //Values Possible 1 Field 2 town 3 
	int sideNRoad; //Values 0 or 1
				   
	/*East*/
	int sideE;
	int sideERoad;

	/*South*/
	int sideS;
	int sideSRoad;

	/*West*/
	int sideW;
	int sideWRoad;

	int church; //Values 1 or 0
	//maybe create a side class but unnessary unless we want to 

public:
	//Tile Side Values
	int getN() {
		return sideN;
	}
	int getE() {
		return sideE;
	}
	int getS(){
		return sideE;
	}
	int getW(){
		return sideW;
	}
    //Road Status
	int getRN() {
		return sideNRoad;
	}
	int getRE() {
		return sideNRoad;
	}
	int getRS() {
		return sideNRoad;
	}
	int getRW() {
		return sideNRoad;
	}
};
