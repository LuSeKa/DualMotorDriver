/* Author: Lukas Kaul, July 2015
 * 
 * This library provides access to the motor shield functionalities.
 * Motors ares referred to by 'A' and 'B', as it is written on the shield.
 * Once the init is performed you can set the pwm of each motor with the setPWM function (8Bit from 0 to 255).
 */ 


#ifndef DualMotorDriver_h
#define DualMotorDriver_h

#include "Arduino.h"


class DualMotorDriver
{
	public:
		DualMotorDriver(); // constructor
		void init(int _dirPinA_1, int _dirPinA_2, int _pwmPinA, int _dirPinB_1, int _dirPinB_2, int _pwmPinB);
		void setPWM(int pwm_A, int pwm_B);
	private:
		int dirPinA_1;
		int dirPinA_2;
		int pwmPinA;
		int dirPinB_1;
		int dirPinB_2;
		int pwmPinB;
};

#endif


/*
 *  In your setup function, make the PWM on Timer 1 faster by changing the timer prescaler from 64 to 1 with the following two lines.
 *  The PWM frequency will then be about 60kHz
 * 
TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00); 
TCCR0B = _BV(CS00); 
 * 
 * 	You need to be carful because this messes with millis(), micros() and delay()
 *  You might want to define custom function such as 
 *  
unsigned long myMicros()
{
	return micros()/64;
}
 *  
 */
