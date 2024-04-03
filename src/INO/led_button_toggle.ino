#include <ezButton.h>

/// constants won't change
const int BUTTON_PIN_1 = 7; // the number of the first pushbutton pin
const int BUTTON_PIN_2 = 8; // the number of the second pushbutton pin
const int BUTTON_PIN_3 = 9; // the number of the third pushbutton pin
const int LED_PIN_1    = 3; // the number of the first LED pin
const int LED_PIN_2    = 2; // the number of the second LED pin
const int LED_PIN_3    = 4; // the number of the third LED pin

ezButton button1(BUTTON_PIN_1); // create ezButton object for the first button attached to pin 7
ezButton button2(BUTTON_PIN_2); // create ezButton object for the second button attached to pin 8
ezButton button3(BUTTON_PIN_3); // create ezButton object for the third button attached to pin 9

// variables will change:
int ledState1 = LOW; // the current state of first LED
int ledState2 = LOW; // the current state of second LED
int ledState3 = LOW; // the current state of third LED

void setup() {
  Serial.begin(9600);            // initialize serial
  pinMode(LED_PIN_1, OUTPUT);    // set first LED pin to output mode
  pinMode(LED_PIN_2, OUTPUT);    // set second LED pin to output mode
  pinMode(LED_PIN_3, OUTPUT);    // set third LED pin to output mode
  button1.setDebounceTime(50);   // set debounce time for first button to 50 milliseconds
  button2.setDebounceTime(50);   // set debounce time for second button to 50 milliseconds
  button3.setDebounceTime(50);   // set debounce time for third button to 50 milliseconds
}

void loop() {
  button1.loop(); // MUST call the loop() function for first button first
  button2.loop(); // Then call the loop() function for second button
  button3.loop(); // Then call the loop() function for third button

  if (button1.isPressed()) {
    ledState1 = !ledState1;
    digitalWrite(LED_PIN_1, ledState1);
    if (ledState1 == HIGH) {
      Serial.println("11");
    } else {
      Serial.println("10");
    }
  }

  if (button2.isPressed()) {
    ledState2 = !ledState2;
    digitalWrite(LED_PIN_2, ledState2);
    if (ledState2 == HIGH) {
      Serial.println("21");
    } else {
      Serial.println("20");
    }
  }

  if (button3.isPressed()) {
    ledState3 = !ledState3;
    digitalWrite(LED_PIN_3, ledState3);
    if (ledState3 == HIGH) {
      Serial.println("31");
    } else {
      Serial.println("30");
    }
  }
}
