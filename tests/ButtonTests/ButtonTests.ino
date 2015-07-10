#include "TFTMenu.h"
#include "UIComponents.h"
class SampleButton:public Button{
public:
	SampleButton(int x,int y,int width,int height):Button(x,y,width,height){};
	void action(){
		Serial.println("This is sample Button");
	}
};
#define BTN_X 0
#define BTN_Y 0
#define BTN_HEIGHT 240
#define BTN_WIDTH 160
SampleButton button(BTN_X,BTN_Y,BTN_WIDTH,BTN_HEIGHT);
void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:
  button.action();
}
