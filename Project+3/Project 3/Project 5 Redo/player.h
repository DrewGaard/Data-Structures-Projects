#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
	string name;
	int age;
	int GP;
	int crystals;
	string weapon;

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
};

#endif