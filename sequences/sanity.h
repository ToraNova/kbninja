/*
 * Sanity checker, writes Hello
 * on screen
 * HELLO
 */

#ifndef SANITY
#define SANITY

#include "sequence.h"
#include "Keyboard.h"

namespace sanity{

	int launch(void){
	//BEGIN
	Keyboard.releaseAll();
	Keyboard.print("HELLO");
	//END
	return 0;
	}

	const char title[] = "Sanity:Rel-HELLO";
	Sequence *s = new Sequence(launch,title);
};

#endif
