/*
 * Keyboard Sequence to launch notepad.exe
 * and write my email to it
 * chia_jason96@live.com
 */

#ifndef NOTEPAD
#define NOTEPAD

#include "sequence.h"
#include "Keyboard.h"

namespace notepad{

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
	Keyboard.print("notepad.exe");
	delay(100);
	Keyboard.write(KEY_RETURN);

	//Keyboard.print("Made by: ToraNova (chia_jason96@live.com)");

	//END
	return 0;
	}

	const char title[] = "Notepad:write stuff";
	Sequence *s = new Sequence(launch,title);
};

#endif
