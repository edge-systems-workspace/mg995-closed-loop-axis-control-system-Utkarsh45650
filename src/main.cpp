#include <Arduino.h>
#include <Servo.h>

// TODO 1: Create Servo object
Servo myServo;

// TODO 2: Define PWM pin (Use pin 9)
const int servoPin = 9;

// TODO 3: Create variable to store servo angle
int storeAngle = 0;

void setup() {

    // TODO 4: Initialize Serial communication (9600 baud)
    Serial.begin(9600);
    // TODO 5: Attach servo to PWM pin
    myServo.attach(servoPin);
    // TODO 6: Print system initialization message
    Serial.println("MG995 Servo System Initialized");
}

void loop() {

    // TODO 7: Check if Serial data is available
    if(Serial.available() > 0){

        // TODO 8: Read integer angle input from Serial
        int angle = Serial.parseInt();

        // TODO 9:
        // Validate angle range (0–180)
        // If valid → move servo
        // If invalid → print error message
        if(angle >= 0 && angle <= 180){
            myServo.write(angle);
            // TODO 10:
            // Print confirmation message after movement
            Serial.print("Servo moved to angle: ");
            Serial.println(angle);
        } else {
            Serial.println("Error: Angle out of range (0-180)");
        }
        
    }
}