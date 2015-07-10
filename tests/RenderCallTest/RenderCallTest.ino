#include "TFTMenu.h"
#include "UIComponents.h"
class SampleButton:public Button{
public:
	SampleButton(int x,int y,int width,int height):Button(x,y,width,height){};
	void action(){
		Serial.println();
                Serial.print("------------Executing Action on Motor Hit Tile----------------");
		Serial.print( "This is Sample Button");
		Serial.print("--------------------------------------------------------------");
		Serial.println();
	}
	void render(){
		Serial.println();
		Serial.print("------------Rendering Sample Button--------------");
		Serial.print("Successfully rendered Sample Button");
		Serial.print("------------------------------------------------");
		Serial.println();
	}
};
#define BTN_X 0
#define BTN_Y 0
#define BTN_WIDTH 160
#define BTN_HEIGHT 240 
SampleButton sampleButton(BTN_X,BTN_Y,BTN_WIDTH,BTN_HEIGHT);
void setup() {
  // put your setup code here, to run once:
  sampleButton.render();
}

void loop() {
  // put your main code here, to run repeatedly:

}
