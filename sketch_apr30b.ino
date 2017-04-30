const int ledPin =  LED_BUILTIN;

int ledState = LOW;             
unsigned long lastLEDblink = 0;
long interval = 1000;
int potPin = A0;
long pot = 0;

int switchPin = 8;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

}

void loop() {


  if (digitalRead(switchPin) == LOW) {
    blink();
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void blink() {

  unsigned long newLEDblink = millis();

  pot = analogRead(potPin);
  interval = pot;

  if (newLEDblink - lastLEDblink >= interval) {

    lastLEDblink = newLEDblink;

    if (ledState == LOW && interval >= 20) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
