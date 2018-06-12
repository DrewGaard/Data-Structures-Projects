//Drew Overgaard
//Comp 53
//Project 7

//-----------------Project 7 Vector RandomBox.cpp-----------------------
//I used vector class from the stl in order to create a class named 
//RandomBox
//RandomBox inherits from the location class
//When the player lands on a RandomBox, they're randomly givin an item
//This item changes each time the player lands on the RandomBox
//I used a vector to store the names of all the random items
//that can be obtained from a RandomBox location
//----------------------------------------------------------------------

//-----------------Project 7 Map Shop.cpp-------------------------------
//I used map clas from the stl in order to store the names of items that can 
//be purchased from the shop
//This will come in handy if I decid to add more items to the shop
//This way everything stays organized according to name
//----------------------------------------------------------------------

//----------------------Side Note Not Related To Project----------------
//I was also in the process of adding an equiped items option
//which would allow the player to equip the items in their inventory
//----------------------------------------------------------------------

#include <iostream>
#include "crystal.h"
#include "Game.h"
#include "location.h"

using namespace std;

int main()
{
	Game newGame;

	newGame.playGame();

}