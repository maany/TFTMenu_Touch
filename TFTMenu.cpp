/*
TFTMenu.cpp

Author: Mayank Sharma(imptodefeat@gmail.com)

This file provides implementations for the methods described in TFTMenu.h
Look at the documentation of TFTMenu.h for overview of the API design concept
and class level API documentation.
The function level API documentation and function implementation documentation is included
in this file.
*/
//#include "stdafx.h"
#include "TFTMenu.h"
//========================================
// definitions for functions in Tile class
//========================================

//-----------------------------------------------------------------------
// detects if the position (x,y) lies in the area occupied by the Tile
// returns true if position (x,y) lies in the area occupied by the Tile
// i.e The tile was hit/ selected by the User 
// returns false otherwise
//-----------------------------------------------------------------------
bool Tile::isHit(int x,int y){
	int HORIZONTAL_LIMIT = bounds.x + bounds.width;
	int VERTICAL_LIMIT = bounds.y + bounds.height;
	bool isHit = false;
	if((x>bounds.x && x<HORIZONTAL_LIMIT) && (y>bounds.y && y<VERTICAL_LIMIT))
		isHit = true;
	return isHit;
}

//---------------------------------------------------------------------------------------
// This function should be called when a Tile is hit.
// It contains the logic (can be Arduino specific) that is executed when the Tile is hit
// Every sub-class of Tile should override this function and provide a custom implementation
// p.s this is a virtual method and not a pure virtual method.
// below is the default implementation for action()
//-----------------------------------------------------------------------------------------
void Tile::action(){
	
}
//-------------------------------------------------------------------------------
// This function will use the TFT specific library to render the Tile 
// on screen. Every subclass of Tile should override this function and this 
// function should be the starting point of all rendering operations of the Tile
// Below is the default implementation for render()
//-------------------------------------------------------------------------------
void Tile::render(){

}

//========================================
// definitions for functions in Menu class
//========================================

// Constructor for the class Menu 
// The argument maxNoOfTiles is optional. It's default value is DEFAULT_STACK_CAPACITY, currently 10
// usage : Menu menu ; creates a Menu that holds up to DEFAULT_STACK_CAPACITY tiles 
// usage : Menu menu(5) ; creates a Menu which can hold up to 5 Tiles
Menu::Menu(int maxNoOfTiles){
	tileList = Stack<Tile>(maxNoOfTiles);
}
//---------------------------------------------------------------------------------------
// Returns the pointer to Tile object.
// This Tile object occupies the region in which the position coordinates (x,y) fall.
// Basically, it returns the Tile/ UI component that was selected by the user
// p.s. The virtual function Tile::action() associated with this Tile should be executed 
//after a call to Menu::getHitTile(int,int)
//----------------------------------------------------------------------------------------
Tile* Menu::getHitTile(int x,int y){
	for(int i=0;i<tileList.size();i++){
		Tile* curTile = tileList[i];
		if(curTile->isHit(x,y)){
			return curTile;
		}
	}
	return '\0';
}
//-----------------------------------------------------------------
// This function should render all the Tiles contained by this Menu
//------------------------------------------------------------------
void Menu::render(){
	for(int i=0;i<tileList.size();i++){
		Tile* tile = tileList[i];
		tile->render();
	}
}






