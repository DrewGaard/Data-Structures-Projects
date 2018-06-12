/*
Lab 2: The Player Class
Drew Overgaard	*/

//FILENAME: player.ccp
// contains the player class methods
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player() //default constructor
{
	name = "";;
	age = 0;
	GP = 0;
	crystals = 0;
	weapon = "";
}
void Player::setName(string n)
{
	name = n;
}
void Player::setAge(int a)
{
	age = a;
}
void Player::setGP(int geepee)			//Keeps track of the players gold pieces.
{
	GP = GP + geepee;
}
void Player::setCrystals(int c)			//Keeps track of the players Magic Crystals.
{
	crystals = crystals + c;
}
void Player::setWeapon(string w)			//Keeps track of the players Magic Crystals.
{
	weapon = w;
}
int Player::getAge()
{
	return age;
}
string Player::getName()
{
	return name;
}
int Player::getGP()
{
	return GP;
}
int Player::getCrystals()
{
	return crystals;
}
string Player::getWeapon()
{
	return weapon;
}
void Player::Print()
{
	cout << "Your name is " << name << endl;
	cout << "You have:" << crystals << " Magic Crystal" << endl;
	cout << "You have:" << GP << " GP" << endl;
	cout << "Your Weapon is a:" << weapon << endl;

}
void Player::displayInventory()
{
	Item *current = inventory.getFirstElement();

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
		cout << "Your inventory is empty." << endl;
	}
}

void Player::displayEquiped() //Work in progress
{
	Item *current = equiped.getFirstElement();

	//cout << current << endl; //For testing
	char playerRe;

	cout << "Would you like to equip an item? y/n" << endl;
	cin >> playerRe;

	if (playerRe = 'y')
	{
		string itemToEquip;
		cout << "What do you want to equip?" << endl;
		cin >> itemToEquip;
		Item *i;
		i = inventory.remove(itemToEquip);
		equipItem(i);
	}

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
		cout << "Your do not have any items equiped." << endl;
	}
}

Item *Player::dropItem()
{
	string name;
	string shouldDrop;
	cout << "Would you like to drop an item? Enter 'yes' if you do." << endl;
	cin >> shouldDrop;
	if (shouldDrop == "yes")
	{
		if (inventory.getFirstElement() != 0)
		{
			cout << "What do you want to drop?" << endl;
			cin >> name;
			Item *i;
			
			i = inventory.remove(name);
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
	return 0;
}

Item *Player::unequip()
{
	string name;
	string shouldDrop;
	cout << "Would you like to unequip an item? Enter 'yes' if you do." << endl;
	cin >> shouldDrop;
	if (shouldDrop == "yes")
	{
		if (equiped.getFirstElement() != 0)
		{
			cout << "What do you want to unequip?" << endl;
			cin >> name;
			Item *i;

			inventory.insert(i);
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
	return 0;
}

void Player::pickUpItem(Item* i)
{
	inventory.insert(i);
}

void Player::equipItem(Item* i)
{
	equiped.insert(i);
}