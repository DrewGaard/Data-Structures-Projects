//Drew Overgaard
//Comp 53
//Project 7

#ifndef CRYSTAL_H
#define CRYSTAL_H

#include "location.h"


class crystal : public location
{
protected:
	bool taken;
	char symbol = 'c';

public:
	crystal(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif