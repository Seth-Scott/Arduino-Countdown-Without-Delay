const int LED=13;

const int button=12;
      int buttonState;

unsigned long countdownBegin;
unsigned long countdown=5000;

void setup() {

  //assigns digital pins as either inputs or outputs 
    pinMode(LED,OUTPUT);
    pinMode(button,INPUT);

  //allows the user to use a button without an external resistor
  digitalWrite(button,HIGH);

  Serial.begin(9600);
}

void loop() {
  //checks the state of the button (if you press the button it will read 0, unpressed will read 1)
    buttonState=digitalRead(button);
    Serial.println(currentMillis);

  //if the button is pressed, peg the countdownBegin int to millis() at the moment it was pressed, turns on the light 
    if(buttonState==0){
      countdownBegin=millis();
      digitalWrite(LED,HIGH);
    }
  // if the current time ( millis() ) is greater than or equal to the sum of the time the button was pressed, and the user established countdown (in milliseconds), turn off the light 
    if(millis() >= countdownBegin + countdown){
      digitalWrite(LED,LOW);
    }
}
