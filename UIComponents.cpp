/*
UIComponents.cppp

Author: Mayank Sharma(imptodefeat@gmail.com)

This file provides implementations for the methods described in TFTMenu.h
Look at the documentation of TFTMenu.h for overview of the API design concept
and class level API documentation.
The function level API documentation and function implementation documentation is included
in this file.
*/

#include "stdafx.h"
#include "UIComponents.h"

Button::Button(int x,int y,int width, int height){
	Bounds bounds;
	bounds.x=x;
	bounds.y=y;
	bounds.width=width;
	bounds.height=height;
	this->bounds=bounds;
}
void Button::action(){

}
void Button::render(){

}
Rectangle::Rectangle(int x,int y,int width, int height){
	Bounds bounds;
	bounds.x=x;
	bounds.y=y;
	bounds.width=width;
	bounds.height=height;
	this->bounds=bounds;

}
void Rectangle::action(){

}
void Rectangle::render(){

}