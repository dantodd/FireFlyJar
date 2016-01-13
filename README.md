# FireFlyJar
Build a firefly jar with an Arduino and a couple yellow LEDs.

FireFlyJar is a simple program that flashes 3 LEDs to simulate Fire Flies. You can put them into a mason jar to look like you’ve trapped the flies in the jar. 

You can also view the build on Instructables if you want. http://www.instructables.com/id/Fire-Fly-Jar-Arduino/


###Hardware
The sketch uses an Arduino Nano (I used the cheapie from off shore), 3 X yellow/orange LEDs, 3 X 330 ohm resistors, one mason jar, and a 9 volt battery.


###How-To setup hardware
Just attach a wire to the positive leg of each LED. Attach the other end of the wire to Arduino pins 9, 10, and 11 so that one LED is attached to each pin. Now solder a resistor to the negative leg and solder some wire to the other end of the resistor. Attach these wires to the ground pin on the Arduino. You’re all set to test the hardware. Plug the Arduino into your computer and load up the provided sketch using the Arduino software. 
	##Hints:
I used stranded wire for the positive leads and solid wire (22 AWG) for the ground. This gave me enough rigidness to position the LEDs in the jar and have them somewhat stay in place. I also covered the leads in heat shrink tubing. I also spray painted the jar (outside, I tried the inside, it didn't work) with “window frost” paint from Rustoleum.


##Versions:

FireFlyJar-Continuously-0.1 
LEDs run continually.


Version FireFlyJar-Timeout-0.2
LEDs run for a selectable time and then automatically turn off and the Arduino goes into power down mode consuming less power but the voltage regulator is still running unless you provide power directly to the 5V pin circumventing the regulator.




##Prices as of 7/21/2015
eBay:
Arduino nano: $3
LEDs: $9 for 300 assorted colors in 3mm and 5mm sizes (that’s about 3 cents each)
Resistors: about a penny each if you buy any decent assortment.
about $23 for enough supplies to make 1 and each incremental jar is just $3 (But you have to wait for shipping from China/Hong Kong/Singapore)

Radio Shack (if you can find one open anymore)
Arduino Micro (nearest they have to a nano) $35
Resistors: 33ohm 5pack $1.50
LEDs: $1.99@ $6
About $42.50/jar


**Copyright Dan Todd**
License: GPL version 3

DanTodd@dantodd.com

