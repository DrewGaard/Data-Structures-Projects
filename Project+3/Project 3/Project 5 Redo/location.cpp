#include <iostream>
#include "location.h"

using namespace std;

location::location(char s)
{
	symbol = 's';
	visited = false;
}

void location::setVisited(bool v)
{
	visited = v;
}

void location::setSymbol(char s)
{
	symbol = s;
}

bool location::getVisited()
{
	return visited;
}

char location::getSymbol()
{
	return symbol;
}

void location::draw()
{
	if (visited == true)
	{
		cout << symbol;
	}
	else
	{
		cout << ".";
	}
}

int location::visit(Player &p)
{
	visited = true;
	return 1;
}