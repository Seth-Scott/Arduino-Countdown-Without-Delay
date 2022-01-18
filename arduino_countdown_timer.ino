/*/ 
Countdown without the delay command:
This code uses the millis() function to "delay" an action (in this case, illuminate an LED (built-in and/or digital pin 13) five seconds after the button (digital pin 12) is pressed)
The delay command is useful, but it does not allow the Arduino to perform other tasks while the delay is active. In some cases, it isn't as accurate as the millis() command. 


NOTE: The word "countdown" is used frequently here, but in reality, we're counting UP with the internal clock of the Arduino. 
      In practical terms, we're starting the clock from the moment the button is pressed, and turning the LED off the moment the internal clock reaches the sum of "countdownBegin" + "countdown"  

2021 Seth Scott
/*/

const int LED=13;
const int button=12;

//assigns the state (pressed/not pressed) of the button to an integer
int buttonState;

//the exact moment which millis() will be pegged to when the button is pressed
unsigned long countdownBegin;

//adjust this time in milliseconds, the LED will turn off after time has elapsed
unsigned long countdown=5000;

void setup() { 
  pinMode(LED,OUTPUT);
  pinMode(button,INPUT);

  //allows the user to use a button without an external resistor
  digitalWrite(button,HIGH);

  Serial.begin(9600);
}

void loop() {
  //checks the state of the button (if you press the button it will read 0, unpressed will read 1)
  buttonState=digitalRead(button);
  Serial.println(countdownBegin);

  //if the button is pressed, peg "countdownBegin" to millis(), turns on the light 
  if(buttonState==0){
    countdownBegin=millis();
    digitalWrite(LED,HIGH);
  }
  //once millis() reaches the sum of "countdownBegin" and "countdown", turn off the light 
  if(millis() >= countdownBegin + countdown){
    digitalWrite(LED,LOW);
  }
}
