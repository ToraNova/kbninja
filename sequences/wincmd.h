/*
 * WINCMD launch
 * and write my email to it
 * chia_jason96@live.com
 */

#include "Keyboard.h"

#ifndef WINCMD
#define WINCMD


namespace wincmd{

int launch(){
	Keyboard.press(KEY_LEFT_GUI);
	Keyboard.press('r');
	delay(100);
	Keyboard.releaseAll();
	delay(1500);

	Keyboard.println("cmd");
}

}

#endif
