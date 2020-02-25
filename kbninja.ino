/*
	Keyboard Ninja
	A simple keyboard stroke injector with 2 button control
*/
#include "Keyboard.h"
#include "timint.h"
#include "programs.h"
#include "gui.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 4);

//button B shud be pushed for at least 500ms
#define DEBOUNCE_MIN 5

//PINS
const int bA = 7; //button A
const int bB = 15; //button B
const int Tx = 0;
const int Rx = 1;
const int lA = 5;  //LED A

//VOLATILES
volatile int LSTATE = 0;   // for checking the state of a pushButton
volatile int PSELST = 0;
volatile unsigned int debc = 0;
volatile unsigned int ictr = 0;
volatile int i,j;

void setup() {
	t1setup();

	pinMode( bA, INPUT);
	pinMode( bB, INPUT);
	attachInterrupt( digitalPinToInterrupt(bA), handleApush, FALLING);
	pinMode( LED_BUILTIN, OUTPUT);
	pinMode( lA, OUTPUT);
	// initialize control over the keyboard:
	Keyboard.begin();

	// init OLED
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
	digitalWrite( lA, LOW); //on LED to indicate error
		while(true){//don't proceed}
	}
	}else{
		display.setTextSize(1);
		display.setTextColor(SSD1306_WHITE);
	}
	display.display();

	//switch off LEDs
	digitalWrite( lA, HIGH); //turn off lA (active LOW)
	//PORTD |= (1<<PORTD5);
	//PORTB |= (1<<PORTB0);
	//force TX and RX LED to OFF by setting them up as inputs
	DDRD &= ~(1<<DDD5);
	DDRB &= ~(1<<DDB0);
}

void loop() {

	initgui( &display );
	//default cursor at prog0
	display.setCursor(0,PROG_VSTART);
	display.write('>');
	display.display();

	while(true){
	//main loop
		while( digitalRead( bB ) == HIGH ){}
		debc = 0;
		while( digitalRead( bB ) == LOW ){
			debc++;
			delay(1);
		}
		if(debc < DEBOUNCE_MIN){
			//probably noice, we expect press more than 500ms
			continue;
		}
		//bB button pressed and released, debounced
		PSELST++;
		if(PSELST > 4) PSELST = 0;
		display.clearDisplay();
		initgui( &display );
		display.setCursor(0,PROG_VSTART+TXTHEIGHT*PSELST);
		display.write('>');
		display.display();

	}
}

void handleApush(){
	//Keyboard.print("Hello World!");
	digitalWrite( lA, LOW); //DEBUG TEST
	seq[PSELST]->launch();
	digitalWrite( lA, HIGH); //DEBUG TEST
}

ISR(TIMER1_COMPA_vect){
	ictr++;
	//LSTATE = !LSTATE;
	//digitalWrite(LED_BUILTIN, LSTATE);
}
