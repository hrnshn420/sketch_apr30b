
const int ledPin =  LED_BUILTIN;// the number of the LED pin

int ledState = LOW;             // ledState used to set the LED

unsigned long lastLEDblink = 0;        // will store last time LED was updated

long interval = 1000;           // interval at which to blink (milliseconds)

int potPin = A0;
long pot = 0;

int switchPin = 8;

void setup() {
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

    if (ledState == LOW && interval >= 20) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);
  }
}
