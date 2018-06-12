#include "Game.h"
#include "crystal.h"
#include "Monster.h"
#include "Shop.h"
#include "Princess.h"
#include "location.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void Game::setUpGame()
{
	ifstream gameboard;
	gameboard.open("GameBoard.txt");
	string data;

	playerRow = 0;
	playerCol = 0;

	string* board;
	board = new string[10000]; //a string array to hold the input from the file. I set it equall to 10000


	int i = 0;
	while (!gameboard.eof())
	{
			gameboard >> data;
			board[i] = data;
			i++;
	}
	gameboard.close();


	rows = atoi(board[0].c_str()); //Set the first item in the array equall to row and the second equall to col
	cols = atoi(board[1].c_str());


	world = new location **[rows];

	for (int r = 0; r < rows; r++)
	{
		world[r] = new location *[cols]; //cols
	}

	int space = 2; //Stoped here				//This counter must be set to 2 because [0] and [1] are the rows and cols
	
	for (int r = 0; r < rows; r++)
	{
		cout << endl;
		for (int c = 0; c < cols; c++)
		{
			if (board[space] == "o")		//Stoped here
			{
				world[r][c] = new location(); //Fill in all the rows
				space++;
			}
			else if (board[space] == "crystal")
			{
				world[r][c] = new crystal('c'); //Fill in all the rows
				space++;
			}
			else if (board[space] == "monster")
			{
				world[r][c] = new Monster('m'); //Fill in all the rows
				space++;
			}
			else if (board[space] == "shop")
			{
				world[r][c] = new Shop('s'); //Fill in all the rows
				space++;
			}
			else if (board[space] == "princess")
			{
				world[r][c] = new Princess('p'); //Fill in all the rows
				space++;
			}
			else
			{
				cout << "There must be a mistake in the Game Board file you're using. Please only use objects that have been defined." << endl;
			}
		}
	}
	
	cout << "Welcome to this awesome Adventure Game! Can you defeat the monsters and theives in order to save the princess?" << endl;
	//Get the name the player wants to use and tell them information about the gmae.
	char name[50] = " ";							//Turned this into a char so I could get names with spaces
	cout << "Please enter a name for your player." << endl;
	cin.getline(name, 50);
	cout << "You can press 'i' when it's your move during the game to see information about your player." << endl;
	cout << "Have fun." << endl;

	p.setName(name);
}


//Saving this because it's what I did during the lab
/*
void Game::setUpGame()
{
	rows = 4;
	cols = 4;

	playerRow = 0;
	playerCol = 0;

	world = new location **[rows];

	for (int r = 0; r < rows; r++)
	{
		world[r] = new location *[cols]; //cols
	}
	
	world[0][0] = new location(); //Fill in all the rows
	world[0][1] = new crystal('c');
	world[0][2] = new location();
	world[0][3] = new location();

	world[1][0] = new crystal('c');
	world[1][1] = new location();
	world[1][2] = new location();
	world[1][3] = new location();

	world[2][0] = new location();
	world[2][1] = new location();
	world[2][2] = new location();
	world[2][3] = new location();

	world[3][0] = new location();
	world[3][1] = new location();
	world[3][2] = new location();
	world[3][3] = new location();
	
	


	//Get data about player here
}

*/

void Game::drawGame()
{
	for (int r = 0; r < rows; r++)
	{
		cout << endl;						//Added to make a square shape
		for (int c = 0; c < cols; c++)
		{
			if (playerRow == r && playerCol == c)
			{
				cout << "P";
				//world[r][c]->visit(p);				//Call the visit method on the spot where the player moves. Didn't need this here since I call it in the playGame() function
			}
			else
			{
				world[r][c]->draw();
			}
		}

	}
	cout << endl;
}

void Game::playGame()
{
	setUpGame();						//This function was causing problems
	char move;
	int gameState = 2;
	do
	{
		drawGame();
		cout << "Which way would you like to move? (w (up), a (left), s (down), d (right))." << endl;
		cin >> move;
		if (move == 'w' && playerRow > 0)							//Up
		{
			playerRow--;			
		}
		else if (move == 'a' && playerCol > 0)						//Left
		{
			playerCol--;
		}
		else if (move == 's' && playerRow < rows - 1)				//Down
		{
			playerRow++;
		}
		else if (move == 'd' && playerCol < cols - 1)				//Right
		{
			playerCol++;
		}
		else if (move == 'i')			//I added this option so the player can see what they have collected throught the game
		{
			p.Print();
		}
		else
		{
			cout << "You can't do that!" << endl;
		}

		world[playerRow][playerCol]->visit(p);


	} while (gameState > 1);
}

Game::~Game()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			delete world[r][c];
		}
	}
	for (int r2 = 0; r2 < rows; r2++)
	{
		delete[] world[r2];
	}
	delete[] world;
}