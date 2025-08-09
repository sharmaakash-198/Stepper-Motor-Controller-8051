#include <reg51.h>

#define STEPPER P2    // Port 2 is connected to the stepper motor driver

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++) {
        for(j = 0; j < 1275; j++);
    }
}

// Function to rotate the stepper motor clockwise
void Stepper_CW() {
    // Half-step sequence for clockwise rotation
    STEPPER = 0x09;  // 0000 1001
    delay(10);
    STEPPER = 0x0C;  // 0000 1100
    delay(10);
    STEPPER = 0x06;  // 0000 0110
    delay(10);
    STEPPER = 0x03;  // 0000 0011
    delay(10);
}

// Function to rotate the stepper motor counterclockwise
void Stepper_CCW() {
    // Half-step sequence for counterclockwise rotation
    STEPPER = 0x03;  // 0000 0011
    delay(10);
    STEPPER = 0x06;  // 0000 0110
    delay(10);
    STEPPER = 0x0C;  // 0000 1100
    delay(10);
    STEPPER = 0x09;  // 0000 1001
    delay(10);
}

void main() {
    while(1) {
        Stepper_CW();    // Rotate clockwise
        delay(200);      // Wait for a moment
        Stepper_CCW();   // Rotate counterclockwise
        delay(200);      // Wait for a moment
    }
}
