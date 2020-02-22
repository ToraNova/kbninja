/*
	Keyboard Ninja
	A simple keyboard stroke injector with 2 button control
*/
#include "Keyboard.h"
#include "timint.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 4);
#define SZ1WIDTH 21

//PINS
const int bA = 7; //button A
const int bB = 15; //button B
const int Tx = 0;
const int Rx = 1;
const int lA = 5;  //LED A

//VOLATILES
volatile int LSTATE = 0;   // for checking the state of a pushButton
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

	display.clearDisplay();
	display.setCursor(0,0);
	display.println(F("KeyboardNinja v1.0"));
	display.setTextColor(SSD1306_BLACK,SSD1306_WHITE);
	for(i=0;i<SZ1WIDTH;i++){
		display.write('=');
	}
	display.display(); //update display

	while(true){
	//main loop

	}
}

void handleApush(){
	Keyboard.print("Hello World!");
	//digitalWrite( lA, LOW);
}

ISR(TIMER1_COMPA_vect){
	ictr++;
	//LSTATE = !LSTATE;
	//digitalWrite(LED_BUILTIN, LSTATE);
}
