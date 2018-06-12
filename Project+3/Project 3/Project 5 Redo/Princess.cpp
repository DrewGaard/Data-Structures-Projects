#include "princess.h"
#include <iostream>
#include <ctime>
#include <time.h>

Princess::Princess(char s)
	: location(s)
{
	taken = false;
}

void Princess::setTaken(bool t)
{
	taken = t;
}

bool Princess::getTaken()
{
	return taken;
}

void Princess::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)					//If the user takes the crystal we set the location to 's'
		cout << "s";
	else
		cout << ".";
}

int Princess::visit(Player &p)				//Pass in the player object by reference so we know when the player lands on a crystal object
{
	char playerRe;
	int die;
	if (taken == false)
	{
		visited = true;
		cout << "You found the missing princess! She was kidnapped by a gang of theives seeking a ransom!" << endl;
		cout << "You can save her by paying the thieves 18 of your GP OR you could fighting them!" << endl;
		cout << "Press 'r' to pay the ransom and 'f' to fight the thieves." << endl;
		cin >> playerRe;
		if (playerRe == 'r' && p.getGP() >= 18)
		{
			taken = true;
			cout << "You decided to pay the thieves what they wanted. You free the princess." << endl;
		}
		else if (playerRe == 'f')
		{
			cout << "You are a true Knight! You decide to fight the theives." << endl;
			taken = false;
			do
			{
				cout << "Press 'r' to roll a die. " << endl;
				cout << "If you roll anything greater than a 4 you defeat the thieves. Good luck. You'll need it." << endl;
				cin >> playerRe;
				if (playerRe == 'r')
				{
					die = (rand() % 6) + 1;
					if (die >= 4)
					{
						taken = true;
						cout << "Huray! You have defeated the thieves! You saved the princess! Congratulations!" << endl;
						cout << "You get 15GP!" << endl;
						p.setGP(15);
						cout << "You now have a total of " << p.getGP() << "GP!" << endl;
					}
					else
					{
						cout << "Unfortunatly the thieves defeated you. Try again!" << endl;
						taken = false;
					}
				}
			} while (taken != true);
		}
		else
		{
			cout << "You do not have enough GP to pay the Ransom, or you pressed the wrong key." << endl;
		}
	}
	return 1;
}