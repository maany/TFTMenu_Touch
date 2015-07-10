/*
TFTMenu.h

Author : Mayank Sharma(imptodefeat@gmail.com)

This header file defines classes that form the basic building blocks of a Menu.
The menu can be rendered on a TFT screen after integrating it with the Arduino TFT Library.
The most important class is the Tile class. Each Menu acts as a container for an array of Tile objects.
Each Tile represents a single User Interface component such as a button, slider, text area etc.
p.s this header defines the parent Tile class for all these UI components.
Class level API documentation is included in this header file. 
Function level API and function implementation documentation is included in the associated TFTMenu.cpp
*/
#ifndef Menu_h
#define Menu_h
#define DEFAULT_STACK_CAPACITY 10
#include "DataStructures.h"

//-----------------------------------------------------------------
// Class for containing the screen position and dimensions for a Tile
//------------------------------------------------------------------
class Bounds{
	public : 
		int x;
		int y;
		int height;
		int width;
};
//-------------------------------------------------------------------------------------------
// Object of this class represent a single UI component such as button, slider, text area etc.
//--------------------------------------------------------------------------------------------
class Tile{
	public:
	int Color;
	Bounds bounds;
	char message[10];
	bool isHit(int x, int y);
	virtual void action();
	virtual void render();
	
};
//-------------------------------------------------------------------------------------------
// Menu is a container for different UI components. Represents a single screen cconfiguration 
// with which the user can interact/
//--------------------------------------------------------------------------------------------
class Menu{
	public:
		Stack<Tile> tileList;
		Tile* getHitTile(int x, int y);
		Menu(int maxNoOfTiles=DEFAULT_STACK_CAPACITY);
		void render();
};
//----------------------------------------------------------------------------------
// Class provding utility features for managing navigation through different Menu's.
//-----------------------------------------------------------------------------------
class MenuManager{
	public:
	static Menu curMenu;
	static Stack<Menu> navigationStack;
	void renderMenu();
};


#endif
