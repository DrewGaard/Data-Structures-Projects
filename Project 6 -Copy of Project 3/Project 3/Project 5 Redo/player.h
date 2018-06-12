#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "LinkedList.h"

using namespace std;

class Player
{
private:
	string name;
	int age;
	int GP;
	int crystals;
	string weapon;
	LinkedList inventory;

public:  
	Player();

	void setName(string n);
	void setAge(int a);
	void setGP(int geepee);
	void setCrystals(int c);
	void setWeapon(string w);

	string getName();
	int getAge();
	int getGP();
	int getCrystals();
	string getWeapon();

	void Print();  
	void displayInventory();
	Item *dropItem();
	void pickUpItem(Item* i);
	void pickUpGP(int gp);			//This function will just handle adding gold to the players inventory
};

#endif