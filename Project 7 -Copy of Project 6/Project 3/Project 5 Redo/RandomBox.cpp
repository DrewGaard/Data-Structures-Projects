//Drew Overgaard
//Comp 53
//Project 6

#include "RandomBox.h"
#include <iostream>
#include <vector>

using namespace std;

RandomBox::RandomBox(char s)
	: location(s)
{
	taken = false;
}

void RandomBox::setTaken(bool t)
{
	taken = t;
}

bool RandomBox::getTaken()
{
	return taken;
}

void RandomBox::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)					//If the user takes the crystal we set the location to 's'
		cout << "s";
	else
		cout << ".";
}

int RandomBox::visit(Player &p)				//Pass in the player object by reference so we know when the player lands on a crystal object
{
	char playerRe;

	//I used vectors as a way to store items that can be collected from the random box.

	int randNum = (rand() % 12) + 1;
	vector <string> items;
	items.push_back("Bones");
	items.push_back("Chicken");
	items.push_back("Book");
	items.push_back("Steak");
	items.push_back("Shield");
	items.push_back("Robes");
	items.push_back("Helmet");
	items.push_back("Platelegs");
	items.push_back("Platebody");
	items.push_back("Fez");
	items.push_back("Santa Hat");
	items.push_back("Party Hat");
	items.push_back("Staff");

	if (taken == false)
	{
		visited = true;
		cout << "You found a Random Box location! Congratulations!" << endl;
		cout << "You can pick up the first item you get or come back to the square for a different random item." << endl;
		cout << "You found " << items[randNum] << endl;
		cout << "Would you like to take the " << items[randNum] << "? Press 'y' for yes and 'n' for no." << endl;
		cin >> playerRe;
		if (playerRe == 'y')
		{
			taken = true;
			cout << "You took the " << items[randNum] << endl;
			//p.setCrystals(1);
			Item *c = new Item(items[randNum]);
			p.pickUpItem(c);
			ground.remove(items[randNum]);
		}
		else
		{
			cout << "You decide not to take the " << items[randNum] << endl;
			taken = false;
		}
	}
	return 1;
}
