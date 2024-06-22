/*
 * Button-controlled Relay with Debounce
 * 
 * This code controls a relay using a button. When the button is pressed,
 * the relay is turned on for 5ms, off for 5ms, on for 50ms, and then off again.
 * The relay is only triggered once per button press.
 * 
 * Created with assistance from ChatGPT.
 */

const int buttonPin = 8;   // Pin connected to the button
const int relayPin = 2;    // Pin connected to the relay

bool previousButtonState = HIGH; // Tracks the previous state of the button
bool relayTriggered = false;     // Tracks if the relay has been triggered

void setup() {
  Serial.begin(9600);      // Initialize serial communication for debugging
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  pinMode(relayPin, OUTPUT);         // Set relay pin as output
  digitalWrite(relayPin, HIGH);      // Ensure relay is initially off (active-low configuration)
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.print("Button State: ");
  Serial.println(buttonState);

  // Check if button state has changed from not pressed to pressed
  if (buttonState == LOW && previousButtonState == HIGH) {
    relayTriggered = true;
  }

  if (relayTriggered) {
    Serial.println("Button Pressed: Turning Relay ON for 5ms");
    // Turn on the relay (active-low)
    digitalWrite(relayPin, LOW);
    delay(5); // Wait for 5 milliseconds

    Serial.println("Turning Relay OFF for 5ms");
    // Turn off the relay (active-low)
    digitalWrite(relayPin, HIGH);
    delay(5); // Wait for 5 milliseconds

    Serial.println("Turning Relay ON for 40ms");
    // Turn on the relay (active-low)
    digitalWrite(relayPin, LOW);
    delay(40); // Wait for 40 milliseconds

    Serial.println("Turning Relay OFF");
    // Turn off the relay (active-low)
    digitalWrite(relayPin, HIGH);

    // Mark the relay as triggered
    relayTriggered = false;

    // Debounce delay to avoid multiple triggers
    delay(500); // Adjust as necessary to suit debounce requirements
  }

  // Update the previous button state
  previousButtonState = buttonState;

  delay(100); // Add a short delay to reduce serial output spam
}
