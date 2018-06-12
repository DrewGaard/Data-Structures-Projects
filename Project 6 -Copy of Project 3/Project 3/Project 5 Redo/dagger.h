#ifndef DAGGER_H
#define DAGGER_H

#include "location.h"


class dagger : public location
{
protected:
	bool taken;
	char symbol = 'c';

public:
	dagger(char s);

	void setTaken(bool t);
	bool getTaken();

	void draw();
	int visit(Player &p);				//Pass in the player object so we know when the player has visited a location
};

#endif