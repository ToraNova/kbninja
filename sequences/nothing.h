/*
 * DO NOTHING
 */

#ifndef NOTHING
#define NOTHING

#include "sequence.h"
#include "Keyboard.h"

namespace nothing{

	int launch(void){
	//BEGIN
	//END
	return 0;
	}

	const char title[] = "Nothing:NO-OP";
	Sequence *s = new Sequence(launch,title);
};

#endif
