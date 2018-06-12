//Drew Overgaard
//Comp 53
//Project 6

#include <iostream>
#include "location.h"

using namespace std;

location::location(char s)
{
	symbol = 's';
	visited = false;
}

void location::setVisited(bool v)
{
	visited = v;
}

void location::setSymbol(char s)
{
	symbol = s;
}

bool location::getVisited()
{
	return visited;
}

char location::getSymbol()
{
	return symbol;
}

void location::draw()
{
	if (visited == true)
	{
		cout << symbol;
	}
	else
	{
		cout << ".";
	}
}

int location::visit(Player &p)
{
	visited = true;
	return 1;
}

Item *location::takeFromGround(Player& p)	//Ask the user if they want to pick an item up off the ground.
{
	if (ground.getFirstElement() > 0)
	{
		char answer = ' ';
		string item = " ";
		cout << "The items at this location are..." << endl;
		displayGround(); //ground.print() - Dont use here
		cout << "Would you like to pick up an item? Press 'y' for yes or 'n' for no." << endl;
		cin >> answer; 

		

		if (answer == 'y')
		{
			if (ground.getFirstElement() != 0)
			{
				cout << "What do you want to pick up?" << endl;
				cin >> item;

				Item *nItem = new Item(item);
				p.pickUpItem(nItem);

				Item *i;

				i = ground.remove(item);

				if (i == 0)
				{
					cout << "The item you entered does not exist." << endl;
				}
				else
				{
					return i;
				}
			}
		}
	}
}

void location::displayGround()
{
	Item *current = ground.getFirstElement();

	//cout << current << endl; //For testing

	if (current != 0)	//Items in the inventory
	{
		while (current != 0)
		{
			cout << current->getName() << endl;
			current = current->getNext();
		}
	}
	else
	{
		cout << "No items at this location" << endl;	//This else case should never happen since the function is only called in the takeFromGround() function that checks if an item is in the ground location first
	}
}