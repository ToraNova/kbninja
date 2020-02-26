
/*
 * Keyboard Sequence to launch notepad.exe
 * and write my email to it
 * chia_jason96@live.com
 */

#ifndef WINSPEAK
#define WINSPEAK

#include "sequence.h"
#include "Keyboard.h"


namespace winspeak{

	int launch(void){
	//BEGIN
	Keyboard.print("PowerShell -Command \"Add-Type –AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('hello');\"");
	delay(100);
	Keyboard.write(KEY_RETURN);

	//END
	return 0;
	}

	const char title[] = "Winspeak:HELLO";
	Sequence *s = new Sequence(launch,title);

};

#endif
