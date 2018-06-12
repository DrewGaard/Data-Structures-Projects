/*
Lab 2: The Player Class
Kyle Wooton
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
//TODO: write code for rest of methods 