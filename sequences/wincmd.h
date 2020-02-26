/*
 * WINCMD launch
 * and write my email to it
 * chia_jason96@live.com
 */

#ifndef WINCMD
#define WINCMD

#include "sequence.h"
#include "Keyboard.h"

namespace wincmd{

	int launch(void){
	//BEGIN
	Keyboard.press(KEY_LEFT_GUI);
	Keyboard.press('r');
	delay(100);
	Keyboard.releaseAll();
	delay(1000);

	//Keyboard.print("notepad.exe");
	//delay(100);
	//Keyboard.write(KEY_RETURN);
	//Keyboard.println("cmd.exe");
	Keyboard.print("cmd.exe");
	delay(100);
	Keyboard.write(KEY_RETURN);

	//END
	return 0;
	}

	const char title[] = "Command:CMD";
	Sequence *s = new Sequence(launch,title);
};

#endif
