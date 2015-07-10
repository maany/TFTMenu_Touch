// TFTMenu-master library
#include "TFTMenu.h"
#include "UIComponents.h"
// Seeed TFTv2 library
#include <stdint.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <SPI.h>

Menu menu;
TouchScreen ts = TouchScreen(XP, YP, XM, YM); //init TouchScreen port pins

class MotorButton: public Button {
  public:
    MotorButton(int x, int y, int width, int height): Button(x, y, width, height) {};
    void action() {
      Serial.println("This is Motor Button");
    }
        void render(){
      Tft.fillRectangle(bounds.x,bounds.y,bounds.width,bounds.height,GREEN);  
    }
};
class MFCButton: public Button {
  public:
    MFCButton(int x, int y, int width, int height): Button(x, y, width, height) {};
    void action() {
      Serial.println("This is MFC Button");
    }
    void render(){
      Tft.fillRectangle(bounds.x,bounds.y,bounds.width,bounds.height,RED);  
    }
};
#define MOTOR_BTN_X 0
#define MOTOR_BTN_Y 0
#define MOTOR_BTN_HEIGHT 240
#define MOTOR_BTN_WIDTH 160
MotorButton motorButton = MotorButton(MOTOR_BTN_X, MOTOR_BTN_Y, MOTOR_BTN_WIDTH, MOTOR_BTN_HEIGHT);

#define MFC_BTN_X 160
#define MFC_BTN_Y 0
#define MFC_BTN_HEIGHT 240
#define MFC_BTN_WIDTH 160
MFCButton mfcButton(MFC_BTN_X, MFC_BTN_X, MFC_BTN_X, MFC_BTN_X);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  TFT_BL_ON;                                          // turn on the background light
  Tft.TFTinit();     // init TFT library
  menu.tileList.push(&motorButton);
  menu.tileList.push(&mfcButton);
  menu.render();
  Tft.fillRectangle(0,0,160,200,RED);  
}

void loop() {
  // put your main code here, to run repeatedly:
  // a point object holds x y and z coordinates.
  Point p = ts.getPoint();

  //map the ADC value read to into pixel co-ordinates

  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);

  if (p.z > __PRESURE) {
      Tile* hitTile = menu.getHitTile(p.x,p.y);
      hitTile->action();
  }
}
