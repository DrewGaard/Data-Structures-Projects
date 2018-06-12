//Drew Overgaard
//Comp 53
//Project 7

#ifndef SHOP_H
#define SHOP_H

#include "location.h"


class Shop : public location
{
protected:
	bool taken;
	char symbol = 'g';

public:
	Shop(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif