const int buttonPin = 8;
const int ledPin = 2;
bool currentButtonState;
bool previousButtonState = HIGH;
bool ledState = LOW;
void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, ledState);
}
void loop() {
    currentButtonState = digitalRead(buttonPin);
    if (previousButtonState == HIGH && currentButtonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }
    previousButtonState = currentButtonState;
}