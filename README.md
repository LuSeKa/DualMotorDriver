# DualMotorDriver
Library to use dual H-bridge motor drivers (L293D or similar) for bi-directional PWM-control of two DC-motors 

## Notes
# Increase PWM-frequency for better control and less noise

In your arduino setup()-function, make the PWM on Timer 1 faster by changing the timer prescaler from 64 to 1 with the following two lines.
The PWM frequency will then be about 60kHz

```cpp
TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00); 
TCCR0B = _BV(CS00); 
```

You need to be carful because this messes with millis(), micros() and delay()
You might want to define custom function such as 

```cpp
unsigned long myMicros()
{
	return micros()/64;
}
```

