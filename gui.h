/*
 * GUI display functions
 */

#include <Adafruit_SSD1306.h>
#include "programs.h"

#define PROG_VSTART 16
#define PROG_HSTART 6
#define TXTHEIGHT 10
#define SZ1WIDTH 21

void initgui(Adafruit_SSD1306 *display){
	volatile int i;

	display->clearDisplay();
	display->setCursor(0,0);
	display->println(F("KeyboardNinja v1.0"));
	display->setTextColor(SSD1306_BLACK,SSD1306_WHITE);
	for(i=0;i<SZ1WIDTH;i++){
		display->write('=');
	}

	display->setTextColor(SSD1306_WHITE);
	for(i=0;i<5;i++){
		display->setCursor(PROG_HSTART,PROG_VSTART+TXTHEIGHT*i);
		//display->println(F(seq[i]->title));
		display->println(seq[i]->title);
	}

	display->display(); //update display
}
