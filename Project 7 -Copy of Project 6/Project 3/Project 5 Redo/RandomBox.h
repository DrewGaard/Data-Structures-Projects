//Drew Overgaard
//Comp 53
//Project 7

#ifndef RANDOMBOX_H
#define RANDOMBOX_H

#include "location.h"


class RandomBox : public location
{
protected:
	bool taken;
	char symbol = 'b';

public:
	RandomBox(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif














/*
vector <string> v(3);

v.push_back("Chain Mail");
v.push_back("Bones");
v.push_back("Fez");
int die2;
string drop = " ";
die2 = (rand() % 6) + 1;
*/