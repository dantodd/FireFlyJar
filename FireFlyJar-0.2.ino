/*
This is based on the Fade tutorial available at https://www.arduino.cc/en/tutorial/fade

I changed it a ton and since I'm not really a programmer it is not optimized at all. 
I'm sure if a pro wanted to follow the same program they could make it much more elegant
But this does work, so there's that.

If you use this or redistribute it please give me a little shout out in the documentation.
dantodd@yahoo.com

Version 0.2
  Added auto-sleep timer to save batteries when used at night as a nightlight.
  This update required the power.h and sleep.h libraries.
*/

#include <avr/power.h>
#include <avr/sleep.h>


/* TimeOut in minutes. Once the lights have been on for this long they will
  turn off and the Arduino will go into sleep mode. The voltage regulator
  won't stop though so the battery will still drain, just much more slowly.
  Press the reset button or cycle the power to restart the lights.
*/
int TimeOut = 20;  // LED timeout in minutes. 


// Adjust these numbers to get the pattern you like. 
// They control how long the lights stay off between flashes
int dark1_interval = 500;  // how long to keep LED1 dark before beginning next flash
int dark2_interval = 750;  // how long to keep LED1 dark before beginning next flash
int dark3_interval = 200;  // how long to keep LED1 dark before beginning next flash


// These are the pins to use for an Arduino Nano. You can use any PWM pin if you like.
int led1 = 9;             // LED1 is attached to pin D9
int led2 = 10;            // LED2 is attached to pin D10
int led3 = 11;            // LED3 is attached to pin D11

int brightness1 = 0;      // how bright LED1 is at start
int brightness2 = 0;      // how bright LED2 is at start
int brightness3 = 160;    // how bright LED3 is at start
int dark1 = 0;            // start with LED1 on
int dark2 = 400;          // start with LED2 in dark period
int dark3 = 0;            // start with LED3 on


// don't change these values as the flash timer may not work if fadeX doesn't hit exactly 0
int fade1 = 1;    // give a starting place for fading LED1 
int fade2 = 1;    // give a starting place for fading LED2
int fade3 = 1;    // give a starting place for fading LED3



// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
} 



// the loop routine runs over and over again forever:
void loop()  { 
  
  // timer to turn off LEDs after TimeOut is reached. Set timeout above
  if (millis() >= (TimeOut * 60000)){
   turnOff();
  }
   
  // turn on LEDs:
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);
  analogWrite(led3, brightness3);

  // change the brightness for next time through the loop:
  brightness1 = brightness1 + fade1;
  brightness2 = brightness2 + fade2;
  brightness3 = brightness3 + fade3;
 
  // reverse the direction of the fading at the ends of the fade: 
  if (brightness1 == 0 || brightness1 == 255) {
    fade1 = -fade1 ; 
  }     
  if (brightness2 == 0 || brightness2 == 255) {
    fade2 = -fade2 ; 
  }     
  if (brightness3 == 0 || brightness3 == 255) {
    fade3 = -fade3 ; 
  }     
  
  
  // If the LED is off this starts a process that keeps the LED off for "darkX_interval" 
  if (brightness1 == 0){
    dark1 = 1;
  }  
  if (brightness2 == 0){
    dark2 = 1;
  }
  if (brightness3 == 0){
    dark3 = 1;
  }
  
  
//  This group of statements keep the LEDs off (brightness = 0)  until darkX_interval cycles have passed, 
//  then it turns the LED on at 100 (on a scale of 0-255). Starting at 100 gives a more realistic flash for a firefly
  if (dark1 != 0){
    dark1 = dark1 + 1 ;
    brightness1 = 0;
    if (dark1 >= dark1_interval){
      dark1 = 0 ;
      brightness1 = 100 ;
    }
  }
  
  if (dark2 != 0){
    dark2 = dark2 + 1 ;
    brightness2 = 0;
    if (dark2 >= dark2_interval){
      dark2 = 0 ;
      brightness2 = 100;
    }
  }

  if (dark3 != 0){
    dark3 = dark3 + 1 ;
    brightness3 = 0;
    if (dark3 >= dark3_interval){
      dark3 = 0 ;
      brightness3 = 100;
    }
  } 
  delay (10);            
}


void turnOff()
{                
// Arduino forum code http://forum.arduino.cc/index.php?topic=53821.0
  byte i;
  
// Ensure no floating pins 0 and 1 are TX/RX and light when low
  for(i=2; i<20 ; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  // Power-down board
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  sleep_enable();
  
  // Disable ADC
  ADCSRA &= ~(1 << ADEN);

  // Power down functions
  PRR = 0xFF;
  
  // added to try and kill RX/TX LEDs
  power_adc_disable(); //disable the clock to the ADC module
  power_spi_disable(); //disable the clock to the SPI module
  power_all_disable();
  
  // Enter sleep mode
  sleep_mode();
}

