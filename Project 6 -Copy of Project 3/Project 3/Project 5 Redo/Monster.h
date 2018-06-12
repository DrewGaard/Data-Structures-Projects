#ifndef MONSTER_H
#define MONSTER_H

#include "location.h"


class Monster : public location
{
protected:
	bool taken;

public:
	Monster(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif