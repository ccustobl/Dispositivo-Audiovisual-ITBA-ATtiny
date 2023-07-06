// ---------------------------------------------------------------------------
//
// Power control program for the Overhead Projector
// Author: Custo Blanch, Christian
// Project: Overhead Projector Phase 2
// ITBA
//
// ---------------------------------------------------------------------------
// Definitions
// ---------------------------------------------------------------------------

// Pins
#define switchPin 0 // Input Pin connected to the switch
#define rpiOffPin 1 // Output Pin connected to the RPi, turned OFF on HIGH
#define ledPin 2 // Output Pin connected to the LED, turned ON on HIGH
#define relayPin 3 // Output Pin connnected to the Relay, turned ON on HIGH

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

const long interval = 15000; // Wait for 15 seconds

// ---------------------------------------------------------------------------
// Variables
// ---------------------------------------------------------------------------

int previousInput = LOW;
    
// ---------------------------------------------------------------------------
// Setup 
// ---------------------------------------------------------------------------

void setup() {
  // Pin Setup
  pinMode(switchPin, INPUT);
  pinMode(rpiOffPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(rpiOffPin, LOW); // Send signal to Rpi
}

// ---------------------------------------------------------------------------
// Main Loop
// ---------------------------------------------------------------------------

void loop() {
  
  // Switch ON
  if (digitalRead(switchPin) == HIGH && previousInput == LOW) {
    delay(100); // Debounce
    digitalWrite(relayPin, HIGH); // Turn Power Source on
    digitalWrite(ledPin, HIGH); // Turn LED on
    previousInput = HIGH;
  }
  
  // Switch OFF
  if (digitalRead(switchPin) == LOW && previousInput == HIGH){
    delay(100); // Debounce
    digitalWrite(rpiOffPin, HIGH); // Send signal to Rpi
    delay(interval);
    digitalWrite(relayPin, LOW); // Turn Power Source off
    digitalWrite(ledPin, LOW); // Turn LED off
    digitalWrite(rpiOffPin, LOW); // Send signal to Rpi
    previousInput = LOW;
  }
  
}

// ---------------------------------------------------------------------------
