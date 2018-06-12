//Drew Overgaard
//Comp 53
//Project 7

#ifndef LOCATION_H
#define LOCATION_H

#include "player.h"
#include "LinkedList.h"

using namespace std;

class location
{
protected:
	bool visited;
	char symbol;
	LinkedList ground;

public:
	location(char s = ' ');

	void setVisited(bool v);
	void setSymbol(char s);

	bool getVisited();
	char getSymbol();

	virtual void draw();
	virtual int visit(Player &p);

	void placeOnGround(Item *i){ ground.insert(i); }
	Item *takeFromGround(Player& p);
	void displayGround();
};

#endif