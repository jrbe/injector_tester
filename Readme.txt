Purpose:

Use anarduino as a fuel injector tester/cleaner. Fuel is flammable and explosive, you should only use injectors with a 
non flammable safety test fluid. There will be no info here on how to construct the test setup, if you burn/blow up 
something or yourself you were using this outide its intended purpse and do so at your own risk.

Why?
Injectors get gunked up when they sit.  If you just assume they're ok you could melt a valve etc. Ths will allow you
to clean the injetors, test their flow rates to each other and help find dead time ssues injectors can have.

My coding skills are definitely lacking.  Looking for anyone interested in helping with this.  It will remain free, here, and will not be sold.

I can't say these are right yet but they loo good to me so far..

Injector calculations
https://docs.google.com/spreadsheets/d/1-0iYCRnV9EqTVuqekWcxBpoHmYXPEqo3CiMfZM1JDNQ/edit?usp=sharing

Arduino IO
https://docs.google.com/spreadsheets/d/1-42Ij2Z3fyxZpGCh83bkqHmCLPAMUJDzzBdpMf1oiDw/edit?usp=sharing

injector drive circuit
http://sonic.net/~mikebr/ecm_555/injector_drvr.html

I2C display (may change)
https://www.adafruit.com/products/714

Menu
#of injectors
360 or 720 mode (once per crank rev or once per cam rev)
rpm (displays max on time)
On time in ms adjustable in microseconds for each xxxxxx (displays off time calculated from inputs)
Minimum off time duty or ms?
Fuel pump prime and post run time

Modes
Find opening time (adjust on time around 1ms to find opening time- auto increment each pulse?)
Test pulse
1/100th flow rate
1/10th flow rate
1/2 flow rate
Full Flow rate
Above flow modes can be 6 seconds - 1/10th cc/min flow at full duty cycle,  60 seconds -full flow at  full duty cycle, 1/10th flow - 12 seconds at half duty cycle, or 120 seconds at half duty cyce.
Clean mode (run for _ minutes -cleaning/test - fluid recycling only)

Display
rpm
# of pulses/counter or elapsed time
mode
on time/of time
duty cycle
injector voltage?


Wish list
Led's to light up spray pattern (adjustable delay from initial inj on and led on for time) can use an I2C chip to drive them.
