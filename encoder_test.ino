
#define ENCODER_OPTIMIZE_INTERRUPTS // comment this out on Non-Teensy boards
#include <Encoder.h>

Encoder EncR1(33, 34);
long positionRight1 = -999;

Encoder EncL1(36, 35);
long positionLeft1 = -999;

Encoder EncL2(32, 31);
long positionLeft2 = -999;

Encoder EncR2(30, 29);
long positionRight2 = -999;


void setup() {

  Serial.begin(9600);
  Serial.println("Encoder Test:");
}

void loop() {
  long newLeft1, newRight1, newLeft2, newRight2;
  newLeft1 = EncL1.read();
  newRight1 = EncR1.read();
  newLeft2 = EncL2.read();
  newRight2 = EncR2.read();
  if (newLeft1 != positionLeft1 || newRight1 != positionRight1 || newLeft2 != positionLeft2 || newRight2 != positionRight2) {
    Serial.print("Left1 = ");
    Serial.print(newLeft1);
    Serial.print(", Right1 = ");
    Serial.print(newRight1);
    Serial.print("Left2 = ");
    Serial.print(newLeft2);
    Serial.print(", Right2 = ");
    Serial.print(newRight2);
    Serial.println();
    positionLeft1 = newLeft1;
    positionRight1 = newRight1;
    positionLeft2 = newLeft2;
    positionRight2 = newRight2;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    EncL1.write(0);
    EncR1.write(0);
    EncL2.write(0);
    EncR2.write(0);
  }
}
