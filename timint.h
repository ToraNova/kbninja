/*
 * timint.h
 * Timer Interrupt based on
 * https://www.instructables.com/id/Arduino-Timer-Interrupts/
 * Edited by ToraNova (chia_jason96@live.com)
 *
 * This is a one-file library (func defined in a header)
 * because arduino doesn't know how to link cpp files
 * and i dun want to put it under the /lib dir
 *
 * PRESCALERS
 * CS02 CS01 	CS00 	Desc
 * 0	0	0	No clock
 * 0	0	1	No prescaler
 * 0	1	0	8 prescaler
 * 0	1	1	64 prescaler
 * 1	0	0	256 prescaler
 * 1	0	1	1024 prescaler
 * 1	1	0	ext clk t0 falling
 * 1	1	1	ext clk t0 rising
 *
 * CS22	CS21 	CS20 	Desc
 * 0	0	0	No clock
 * 0	0	1	No prescaling
 * 0	1	0	8
 * 0	1	1	32
 * 1	0	0	64
 *
 * (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
 * compare match register = [ 16,000,000Hz/ (prescaler * desired interrupt frequency) ] - 1
 *
 * i.e. 8Hz
 * 16M / (8*1024) - 1
 */

#ifdef OCR0A
//setup timer0 (default 2kHz timeout)
//mreg < 256
#define T0MREG 256
void t0setup(){
	cli(); //stop interrupts

	//set timer0 interrupt at 2kHz
	TCCR0A = 0;// set entire TCCR0A register to 0
	TCCR0B = 0;// same for TCCR0B
	TCNT0  = 0;//initialize counter value to 0
	// set compare match register for 2khz increments
	OCR0A = T0MREG;// = (16*10^6) / (2000*64) - 1 (must be <256)
	// turn on CTC mode
	TCCR0A |= (1 << WGM01);
	// Set CS01 and CS00 bits for 64 prescaler
	TCCR0B |= (1 << CS01) | (1 << CS00);
	// enable timer compare interrupt
	TIMSK0 |= (1 << OCIE0A);

	sei(); //reallow interrupts
}
#endif

#ifdef OCR1A
//setup timer1 (default 1Hz timeout)
//mreg < 65536
//#define T1MREG 15624 //1Hz
#define T1MREG 1953 //roughly 8Hz
void t1setup(){
	cli(); //stop interrupts

	//set timer1 interrupt at 1Hz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR1A = T1MREG;// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS10 and CS12 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	sei(); //reallow interrupts
}
#endif

#ifdef OCR2A
//setup timer2 (default 8kHz timeout)
//mreg < 256
#define T2MREG 249
void t2setup(){
	cli(); //stop interrupts

	//set timer2 interrupt at 8kHz
	TCCR2A = 0;// set entire TCCR2A register to 0
	TCCR2B = 0;// same for TCCR2B
	TCNT2  = 0;//initialize counter value to 0
	// set compare match register for 8khz increments
	OCR2A = T2MREG;// = (16*10^6) / (8000*8) - 1 (must be <256)
	// turn on CTC mode
	TCCR2A |= (1 << WGM21);
	// Set CS21 bit for 8 prescaler
	TCCR2B |= (1 << CS21);
	// enable timer compare interrupt
	TIMSK2 |= (1 << OCIE2A);

	sei(); //reallow interrupts
}
#endif

/*
 * Place the following in the main code
 * When the timer overflows, it enters the block
 */

//ISR(TIMER0_COMPA_vect){
//}
//
//ISR(TIMER1_COMPA_vect){
//}
//
//ISR(TIMER2_COMPA_vect){
//}
