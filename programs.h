//sequences

#ifndef PROGRAMS
#define PROGRAMS
#include "sequences/sequence.h"
#include "sequences/notepad.h"
#include "sequences/nothing.h"
#include "sequences/sanity.h"
#include "sequences/winspeak.h"
#include "sequences/wincmd.h"

// PROGXNAME - description
// progx = &namespace::launch; - specify program for that slot

Sequence *seq[5] = {
	sanity::s,
	nothing::s,
	wincmd::s,
	winspeak::s,
	notepad::s
};

#endif
