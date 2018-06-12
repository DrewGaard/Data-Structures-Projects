#ifndef PRINCESS_H
#define PRINCESS_H

#include "location.h"


class Princess : public location
{
protected:
	bool taken;
	char symbol = 'p';

public:
	Princess(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif