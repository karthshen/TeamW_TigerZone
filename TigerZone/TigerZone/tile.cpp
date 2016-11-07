#include "tile.h"

using namespace std;

Tile::Tile()
{
	
}

Tile::~Tile()
{
	this->sideN = NULL;
	this->sideE = NULL;
	this->sideS = NULL;
	this->sideW = NULL;
	
	this->center = NULL;
	
	bool farm = NULL;
	int shield = NULL;
}

Tile::Tile(int north, int east, int south, int west, int center, int shield)
{
	this->sideN = north;
	this->sideE = east;
	this->sideS = sout;
	this->sideW = west;
	this->center = center;
	this->farm = false;
	this->shield = shield;
}


void Tile::Rotate90(){
	int temp = north;
	this->north = east;
	this->east = south;
	this->south = west;
	this->west = temp;
}


//Place meaple

void Tile::PlaceMeaple(string str)
{
	//Someone put soemthing here
}


//Tile Side Values
/* 
 * Value for sideX: 
 * 			0. Empty
 * 			1. Field
 * 			2. Town
 * 			3. Field with Road
 * */
int Tile::getN() {
		cout<<"North is ";
		if(sideN == 0)
		{
			cout<<"Empty"<<endl;
		}
		else if (sideN ==  1)
		{
			cout<<"Field"<<endl;
		}
		else if (sideN == 2)
		{
			cout<<"Town"<<endl;
		}
		else if (sideN == 3)
		{
			cout<<"Field with Road"<<endl;
		}
		return sideN; 
	}
int Tile::getE() {
	cout<<"East is ";
	if(sideE == 0)
	{
		cout<<"Empty"<<endl;
	}
	else if (sideE ==  1)
	{
		cout<<"Field"<<endl;
	}
	else if (sideE == 2)
	{
		cout<<"Town"<<endl;
	}
	else if (sideE == 3)
	{
		cout<<"Field with Road"<<endl;
	}
		return sideE;
	}
int Tile::getS(){
		cout<<"South is ";
		if(sideS == 0)
		{
			cout<<"Empty"<<endl;
		}
		else if (sideS ==  1)
		{
			cout<<"Field"<<endl;
		}
		else if (sideS == 2)
		{
			cout<<"Town"<<endl;
		}
		else if (sideS == 3)
		{
			cout<<"Field with Road"<<endl;
		}
		return sideS;
}

int Tile::getW(){
		cout<<"West is ";
		if(sideW == 0)
		{
			cout<<"Empty"<<endl;
		}
		else if (sideW ==  1)
		{
			cout<<"Field"<<endl;
		}
		else if (sideW == 2)
		{
			cout<<"Town"<<endl;
		}
		else if (sideW == 3)
		{
			cout<<"Field with Road"<<endl;
		}
		return sideW;
}

	
//End Tile side


int Tile::getMeapleN()
{
	return meapleN;
}
int Tile::getMeapleS()
{
	return meapleS;
}
int Tile::getMeapleE()
{
	return meapleE;
}
int Tile::getMeapleW()
{
	return meapleW;
}
