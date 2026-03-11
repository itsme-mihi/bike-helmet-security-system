const int strapPin = 2;      // Reed switch
const int relayPin = 7;      // Relay to control solenoid
const int buzzerPin = 8;     // Buzzer
bool helmetDetected = false;

void setup() {
  pinMode(strapPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Locked by default
  Serial.begin(9600);
}

void loop() {
  // Check strap
  bool strapFastened = digitalRead(strapPin) == LOW;

  // Read serial from Python
  if (Serial.available()) {
    char received = Serial.read();
    helmetDetected = (received == '1');
  }

  if (strapFastened && helmetDetected) {
    digitalWrite(relayPin, HIGH);  // Unlock
    digitalWrite(buzzerPin, LOW);  // No beep
  } else {
    digitalWrite(relayPin, LOW);   // Keep locked
    digitalWrite(buzzerPin, HIGH); // Beep warning
    delay(200);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
