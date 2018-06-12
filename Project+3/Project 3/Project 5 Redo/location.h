#ifndef LOCATION_H
#define LOCATION_H

#include "player.h"

using namespace std;

class location
{
protected:
	bool visited;
	char symbol;

public:
	location(char s = ' ');

	void setVisited(bool v);
	void setSymbol(char s);

	bool getVisited();
	char getSymbol();

	virtual void draw();
	virtual int visit(Player &p);
};

#endif