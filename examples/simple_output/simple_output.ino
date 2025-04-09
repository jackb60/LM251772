#include "LM251772.h"
#include "Wire.h"

LM251772 lm(PB0, 0x6A);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.setSCL(PB6);
  Wire.setSDA(PB7);
  lm.begin();
  lm.setVoltage(12);
  lm.output(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("STATUS: ");
  Serial.println(lm.status());
  Serial.print("CURRENT: ");
  Serial.print(lm.current());
  Serial.println(" A");
  Serial.println();
  delay(1000);
}
