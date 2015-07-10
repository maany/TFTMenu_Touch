#include "TFTMenu.h"

//================
// Test Resources
//================
class MotorTile: public Tile{
	public:
	void action(){
		Serial.println("This is motor Tile");
	}
}motorTile;

class MFCTile:public Tile{
	public:
	void action(){
		Serial.println("This is mfc tile");
	}
}mfcTile;
//==================
// Test Declarations
//===================
bool tileActionTest();
bool menuHitTest();
/* Stack tests*/
bool stackBasicTest();
bool getTileTest();
bool peekTest();


void setup() {
  // put your setup code here, to run once:
  	Serial.println("->Running tileActionTest");
	if(tileActionTest())
		Serial.println("tileActionTest Passed");
	else
		Serial.println("**tileActionTest failed");

	Serial.println("->Running menuHitTest");
	if(menuHitTest())
		Serial.println("menuHitTest Passed");
	else
		Serial.println("**menuHitTest failed");
		
	Serial.println("->Running stackBasicTest");
	if(stackBasicTest())
		Serial.println("stackBasicTest Passed");
	else
		Serial.println("**stackBasicTest failed");
		
	Serial.println("->Running peekTest");
	if(peekTest())
		Serial.println("peekTest Passed");
	else
		Serial.println("**peekTest failed");
		
	Serial.println("->Running menuHitTest");
	if(getTileTest())
		Serial.println("getTileTest Passed");
	else
		Serial.println("**getTileTest failed");
}

void loop() {
  // put your main code here, to run repeatedly:

}

//==================
// TEST DEFINITIONS
//==================
//-----------------------------------------------------------------------------
// @verifies function action() can be called for sub classes of the class Tile 
//------------------------------------------------------------------------------
bool tileActionTest(){
	bool result = false;
	Tile* tile = &motorTile;
	tile->action();
	result = true;
	return result;
}
//---------------------------------------------------------------------------------
// @verifies the correct Tile object is returned when Menu is hit at position (x,y)
//----------------------------------------------------------------------------------
bool menuHitTest(){
	bool result = false;
	Bounds motorTileBounds,mfcTileBounds;
	motorTileBounds.x=0;
	motorTileBounds.y=0;
	motorTileBounds.height=100;
	motorTileBounds.width=100;

	mfcTileBounds.x=100;
	mfcTileBounds.y=0;
	mfcTileBounds.height=100;
	mfcTileBounds.width=100;

	motorTile.bounds = motorTileBounds;
	mfcTileBounds = mfcTileBounds;

	Menu mainMenu;
	mainMenu.tileList.push(&motorTile);
	mainMenu.tileList.push(&mfcTile);
	
	Tile* hitTile = mainMenu.getHitTile(50,50);
	if(hitTile==&motorTile){
		//Serial.println("menuHitTest passed!! ");
		result = true;
	} else {
		//Serial.println("menuHitTest failed");;
	}
	return result;
}
//---------------------------------------------------------------------------------
// @verifies push() and pop() of the custom Stack implementation in DataStrucures.h
//----------------------------------------------------------------------------------
bool stackBasicTest(){
	bool result = false;
	Stack<Tile> stack(5);
	
	Tile tile;
	bool push = stack.push(&tile);
	if(!push){
		return false;
	}
	Tile* retTile = stack.pop();
	if(&tile==retTile)
		result = true;
	
	return result;
	
}
//------------------------------------------------------
// @verifies the overloaded operator [] works for Stack
//------------------------------------------------------
bool getTileTest(){
	bool result = false;
	Stack<Tile> stack(2);
	Tile tile;
	Tile tile2;
	stack.push(&tile);
	stack.push(&tile2);
	Tile* tile3 = stack[1];
	if(tile3==&tile2)
		result=true;
	return result;
}
//-------------------------------------------------------------------------
// the function peek() returns the top element of Stack without popping it.
//-------------------------------------------------------------------------
bool peekTest(){
	bool result = false;
	Stack<Tile> stack(2);
	Tile tile1,tile2;
	stack.push(&tile1);
	stack.push(&tile2);
	if(stack.peek()==&tile2)
		result=true;
	return result;
}
