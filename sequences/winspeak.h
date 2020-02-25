
/*
 * Keyboard Sequence to launch notepad.exe
 * and write my email to it
 * chia_jason96@live.com
 */

#include "Keyboard.h"

#ifndef WINSPEAK
#define WINSPEAK


namespace winspeak{

int launch(){
	Keyboard.print("PowerShell -Command \"Add-Type –AssemblyName System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('hello');\"");
	delay(100);
	Keyboard.write(KEY_RETURN);
}

}

#endif
