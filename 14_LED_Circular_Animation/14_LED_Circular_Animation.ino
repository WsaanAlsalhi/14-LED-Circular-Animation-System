
/*
  14 LED Circular Animation System
  Board: Arduino Nano

  Short Press = Change Pattern
  Long Press  = Change Speed

  6 Patterns
  4 Speeds
  Manual Control Only
*/

const byte LED_COUNT = 14;

const byte leds[LED_COUNT] = {
  2, 3, 4, 5, 6, 7, 8,
  9, 10, 11, 12, 13, A1, A2
};

const byte buttonPin = A0;

// Speed in milliseconds
const int speeds[] = {
  350,  // Slow
  200,  // Medium
  100,  // Fast
  50    // Very Fast
};

const byte SPEED_COUNT = 4;
const byte PATTERN_COUNT = 6;

byte speedLevel = 0;
byte currentPattern = 0;

int position = 0;
int direction = 1;

byte alternateState = 0;
byte heartbeatStep = 0;

unsigned long lastStepTime = 0;
unsigned long lastDebounceTime = 0;
unsigned long pressStartTime = 0;

bool lastReading = HIGH;
bool buttonState = HIGH;
bool longPressHandled = false;

const unsigned long debounceDelay = 40;
const unsigned long longPressTime = 700;


// Turn off all LEDs
void allOff() {
  for (byte i = 0; i < LED_COUNT; i++) {
    digitalWrite(leds[i], LOW);
  }
}


// Turn on one LED
void lightOne(int index) {
  allOff();
  digitalWrite(leds[index], HIGH);
}


// Reset animation
void resetAnimation() {
  position = 0;
  direction = 1;
  alternateState = 0;
  heartbeatStep = 0;

  allOff();

  lastStepTime = millis();
}


// Change pattern
void changePattern() {
  currentPattern++;

  if (currentPattern >= PATTERN_COUNT) {
    currentPattern = 0;
  }

  resetAnimation();
}


// Change speed
void changeSpeed() {
  speedLevel++;

  if (speedLevel >= SPEED_COUNT) {
    speedLevel = 0;
  }

  lastStepTime = millis();
}


// Button control
void checkButton() {

  bool reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceDelay) {

    if (reading != buttonState) {

      buttonState = reading;

      if (buttonState == LOW) {
        pressStartTime = millis();
        longPressHandled = false;
      }

      else {
        if (!longPressHandled) {
          changePattern();
        }
      }
    }
  }

  // Long press detection
  if (buttonState == LOW && !longPressHandled) {

    if (millis() - pressStartTime >= longPressTime) {

      changeSpeed();
      longPressHandled = true;
    }
  }

  lastReading = reading;
}


// Pattern 1: Circular Running Light
void patternRunning() {

  lightOne(position);

  position = (position + 1) % LED_COUNT;
}


// Pattern 2: Alternate Flash
void patternAlternate() {

  allOff();

  for (byte i = 0; i < LED_COUNT; i++) {

    if (i % 2 == alternateState) {
      digitalWrite(leds[i], HIGH);
    }
  }

  alternateState = 1 - alternateState;
}


// Pattern 3: Opposite Chase
void patternOpposite() {

  allOff();

  digitalWrite(leds[position], HIGH);
  digitalWrite(leds[position + 7], HIGH);

  position = (position + 1) % 7;
}


// Pattern 4: Scanner
void patternScanner() {

  lightOne(position);

  position += direction;

  if (position >= LED_COUNT - 1) {
    position = LED_COUNT - 1;
    direction = -1;
  }

  else if (position <= 0) {
    position = 0;
    direction = 1;
  }
}


// Pattern 5: Comet Effect
void patternComet() {

  allOff();

  for (byte j = 0; j < 3; j++) {

    int index = (position - j + LED_COUNT) % LED_COUNT;

    digitalWrite(leds[index], HIGH);
  }

  position = (position + 1) % LED_COUNT;
}


// Pattern 6: Heartbeat
void patternHeartbeat() {

  allOff();

  switch (heartbeatStep) {

    case 0:
    case 2:
      for (byte i = 0; i < LED_COUNT; i++) {
        digitalWrite(leds[i], HIGH);
      }
      break;

    case 1:
    case 3:
      allOff();
      break;
  }

  heartbeatStep++;

  if (heartbeatStep >= 4) {
    heartbeatStep = 0;
  }
}


// Setup
void setup() {

  for (byte i = 0; i < LED_COUNT; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  allOff();

  lastStepTime = millis();
}


// Main loop
void loop() {

  checkButton();

  unsigned long currentTime = millis();

  if (currentTime - lastStepTime >= speeds[speedLevel]) {

    lastStepTime = currentTime;

    switch (currentPattern) {

      case 0:
        patternRunning();
        break;

      case 1:
        patternAlternate();
        break;

      case 2:
        patternOpposite();
        break;

      case 3:
        patternScanner();
        break;

      case 4:
        patternComet();
        break;

      case 5:
        patternHeartbeat();
        break;
    }
  }
}
