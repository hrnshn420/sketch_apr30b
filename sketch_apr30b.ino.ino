// constants won't change. Used here to set a pin number :
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

unsigned long lastLEDblink = 0;        // will store last time LED was updated

// constants won't change :
long interval = 1000;           // interval at which to blink (milliseconds)

int potPin = A0;
long pot = 0;

int switchPin = 8;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  
}



void loop() {
  
  
  if (digitalRead(switchPin) == LOW){
  blink();
  }else{
    digitalWrite(ledPin, LOW);
  }
}

void blink() {
  
  unsigned long newLEDblink = millis();
  
  pot = analogRead(potPin);
  interval = pot;
  if (newLEDblink - lastLEDblink >= interval) {
    // save the last time you blinked the LED
    lastLEDblink = newLEDblink;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW && interval >= 20) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
