# Arduino Countdown Timer

Countdown without the delay command

This code uses the "millis" function to "delay" an action (in this case, illuminate an LED (built-in and/or digital pin 13) five seconds after a button (digital pin 12) is pressed).
The delay command is useful, but it does not allow the Arduino to perform other tasks while the delay is active. In some cases, it isn't as accurate as the "millis" command. 


NOTE: The word "countdown" is used here, but in reality, we're counting UP with the internal clock of the Arduino.

 In practical terms, we're starting the clock from the moment the button is pressed, and turning the LED off the moment the internal clock reaches the sum of "countdownBegin" + "countdown"  
