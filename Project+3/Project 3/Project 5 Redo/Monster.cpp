#include "Monster.h"
#include <iostream>
#include <ctime>
#include <time.h>

Monster::Monster(char s)
	: location(s)
{
	taken = false;
}

void Monster::setTaken(bool t)
{
	taken = t;
}

bool Monster::getTaken()
{
	return taken;
}

void Monster::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)					//If the user takes the crystal we set the location to 's'
		cout << "s";
	else
		cout << ".";
}

int Monster::visit(Player &p)				//Pass in the player object by reference so we know when the player lands on a crystal object
{
	char playerRe;
	srand(time(NULL));
	int die;
	if (visited == false && taken == false)
	{
		visited = true;
		cout << "Oh no! You've come across a Monster! He doesn't look very friendly." << endl;
		cout << "You must battle the Monster in order to survive!" << endl;
		do
		{
			cout << "Press 'r' to roll a die. " << endl;
			cout << "If you roll anything greater than a 2 you defeat the Monster. Good luck. You'll need it." << endl;
			cin >> playerRe;
			if (playerRe == 'r')
			{
				die = (rand() % 6) + 1;
				if (die > 2)
				{
					taken = true;
					cout << "Huray! You have defeated the Monster! You may continue on your journey." << endl;
					cout << "You get 5GP!" << endl;
					p.setGP(5);
					cout << "You now have a total of " << p.getGP() << "GP!" << endl;
				}
				else
				{
					cout << "Unfortunatly the monster defeated you. Try again!" << endl;
					taken = false;
				}
			}
		} while (taken != true);
		return 1;
	}
}