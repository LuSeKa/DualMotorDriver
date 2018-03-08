/* Author: Lukas Kaul, July 2015
 * 
 * This library provides access to the motor shield functionalities.
 * Motors ares referred to by 'A' and 'B', as it is written on the shield.
 * Once the init is performed you can set the pwm of each motor with the setPWM function (8Bit from 0 to 255).
 * 
 */ 

#include "Arduino.h"
#include "DualMotorDriver.h"

DualMotorDriver::DualMotorDriver()
{
}

void DualMotorDriver::init(int _dirPinA_1, int _dirPinA_2, int _pwmPinA, int _dirPinB_1, int _dirPinB_2, int _pwmPinB)
{
  // motor A
  dirPinA_1 = _dirPinA_1;
  dirPinA_2 = _dirPinA_2;
  pwmPinA = _pwmPinA;
  pinMode(dirPinA_1, OUTPUT); //DIR
  pinMode(dirPinA_2, OUTPUT);
  pinMode(pwmPinA, OUTPUT); //PWM
   
  // motor B
  dirPinB_1 = _dirPinB_1;
  dirPinB_2 = _dirPinB_2;
  pwmPinB = _pwmPinB;
  pinMode(dirPinB_1, OUTPUT); //DIR
  pinMode(dirPinB_2, OUTPUT);
  pinMode(pwmPinB, OUTPUT); //PWM
  
  setPWM(0, 0);
}

void DualMotorDriver::setPWM(int pwm_A, int pwm_B)
{
  bool dir_A = true;
  bool dir_B = true;
  if (pwm_A < 0)
  {
    dir_A = false;
    pwm_A = -pwm_A;
  }
  if (pwm_B < 0)
  {
    dir_B = false;
    pwm_B = -pwm_B;
  }
  
  pwm_A = constrain(pwm_A, 0, 255);
  pwm_B = constrain(pwm_B, 0, 255);
    
  // now pwm contains the duty cycle between 0 and 255
  // dir contains the direction: 0 for negative and 1 for positive  

  digitalWrite(dirPinA_1, dir_A);
  digitalWrite(dirPinA_2, !dir_A);
  analogWrite(pwmPinA, pwm_A);

  digitalWrite(dirPinB_1, dir_B);
  digitalWrite(dirPinB_2, !dir_B);
  analogWrite(pwmPinB, pwm_B);
}
