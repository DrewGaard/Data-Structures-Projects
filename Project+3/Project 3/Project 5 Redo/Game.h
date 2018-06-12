#ifndef GAME_H
#define GAME_H

#include "location.h"
#include "player.h"
class Game
{
private:
	location ***world;
	Player p;
	int rows;
	int cols;
	int playerRow;
	int playerCol;
public:
	//Game();
	void setUpGame();
	void drawGame();
	void playGame();
	~Game(); //Destructor
};

#endif