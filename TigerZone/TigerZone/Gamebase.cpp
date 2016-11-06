#include "GameBase.h"

Gamebase::Gamebase()
{
	start = true;
	std::cout << start << std::endl;
}

Gamebase::~Gamebase()
{

}

bool Gamebase::Run() {
	//Gamebase routine
	//returns true while exit has not been pressed
	

	if (start)
	{
		//Board
		//Players/logics
		//Input

		if (isGameEnded())
		{
			start = 0;
			std::cout << "Game Ended" << std::endl;
		}
	}

	return start;
}

bool Gamebase::isGameEnded()
{

	//Just for testing
	bool isEnded = 0;

	std::cout << "Is Game Ended? ";

	std::cin >> isEnded;

	if (isEnded)
	{
		end = 1;
		return end;
	}

	else
	{
		end = 0;
		return end;
	}
}