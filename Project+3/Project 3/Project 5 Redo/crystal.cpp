#include "crystal.h"
#include <iostream>

crystal::crystal(char s)
	: location(s)
{
	taken = false;
}

void crystal::setTaken(bool t)
{
	taken = t;
}

bool crystal::getTaken()
{
	return taken;
}

void crystal::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)					//If the user takes the crystal we set the location to 's'
		cout << "s";
	else
		cout << ".";
}

int crystal::visit(Player &p)				//Pass in the player object by reference so we know when the player lands on a crystal object
{
	char playerRe;
	if (taken == false)
	{
		visited = true;
		cout << "You found a Magic Crystal." << endl;
		cout << "Would you like to take the Magic Crystal? Press 'y' for yes and 'n' for no." << endl;
		cin >> playerRe;
		if (playerRe == 'y')
		{
			taken = true;
			cout << "You took the Magic Crystal!" << endl;
			p.setCrystals(1);
		}
		else
		{
			cout << "You decide not to take the Magic Crystal." << endl;
			taken = false;
		}
	}
	return 1;
}