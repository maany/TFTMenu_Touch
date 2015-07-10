/*
UIComponents.h

Author: Mayank Sharma(imptodefeat@gmail.com)

This class defines standard UI components derived from class Tile.
Override the functions: action() and render() to host 
TFT Touch Screen specific code depending on your hardware.
API class level documentation is provided.
*/
#ifndef UICOMPONENTS_H
#define UICOMPONENTS_H
#include "TFTMenu.h"
class Button:public Tile{
public :
	Button(int,int,int,int);
	virtual void action();
	virtual void render();
};
class Rectangle:public Tile{
public:
	Rectangle(int,int,int,int);
	virtual void action();
	virtual void render();
};
#endif