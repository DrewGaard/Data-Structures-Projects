//Drew Overgaard
//Comp 53
//Project 6

#include "Shop.h"
#include <iostream>

Shop::Shop(char s)
	: location(s)
{
	taken = false;
}

void Shop::setTaken(bool t)
{
	taken = t;
}

bool Shop::getTaken()
{
	return taken;
}

void Shop::draw()
{
	if (visited == true && taken == false)
		cout << symbol;
	else if (taken == true)					//No need for this in the shop class
		cout << "s";
	else
		cout << ".";
}

int Shop::visit(Player &p)				//Pass in the player object by reference so we know when the player lands on a crystal object
{
	char playerRe;

	cout << endl << "You've come to a Shop. You can use your GP to purchase weapons here." << endl;
	cout << "Press 'y' to enter the shop or press 'n' if you don't want to right now." << endl;
	cin >> playerRe;

	if (playerRe == 'n')
	{
		visited = true;
		taken = false;
		return 1;
	}

	
	while (playerRe == 'y')
	{
		char playerRe2;
		visited = true;
		cout << "'Hello, and welcome to my Shop', the Shopkeeper says with a smile." << endl;
		cout << "We have 3 different weapons available. We have a Dagger[2GP], a Short Sword[6GP] and a Long Sword[10GP]." << endl;
		cout << "Press 1 to purchase the Dagger, 2 for the Short Sword, and 3 for the Long Sword." << endl;
		cin >> playerRe2;
		if (playerRe2 == '1' && p.getGP() >= 2)
		{
			cout << "You purchased the Dagger." << endl;
			cout << "That's a fine choice! Enjoy!" << endl;
			p.setGP(-2);
			p.setWeapon("Dagger");
			Item *Weapon = new Item("Dagger");
			p.pickUpItem(Weapon);
			cout << "Press 'n' to exit the shop. Otherwise, press 'y' to continue browsing." << endl;
			cin >> playerRe;
			return 1;
		}
		else if (playerRe2 == '2' && p.getGP() >= 6)
		{
			cout << "You purchased the ShortSword." << endl;
			cout << "That's a great choice! Enjoy!" << endl;
			p.setGP(-6);
			p.setWeapon("ShortSword");
			Item *Weapon = new Item("ShortSword");
			p.pickUpItem(Weapon);
			cout << "Press 'n' to exit the shop. Otherwise, press 'y' to continue browsing." << endl;
			cin >> playerRe;
		}
		else if (playerRe2 == '3' && p.getGP() >= 10)
		{
			cout << "You purchased the Long Sword." << endl;
			cout << "That's the best choice! Enjoy!" << endl;
			p.setGP(-10);
			p.setWeapon("LongSword");
			Item *Weapon = new Item("LongSword");
			p.pickUpItem(Weapon);
			cout << "Press 'n' to exit the shop. Otherwise, press 'y' to continue browsing." << endl;
			cin >> playerRe;
		}
		else
		{
			cout << "You either don't have enough GP for the item you selected or you entered an invalid option." << endl;
			cout << "Press 'n' to exit the shop. Otherwise, press 'y' to continue browsing." << endl;
			cin >> playerRe;
		}
	}
	return 1;
}