#include <Wire.h>

const byte MASTER_ADDR = 0x01;
const byte THROTTLE_ADDR = 0x02;

struct __attribute__((packed)) Throttle_data {
  uint16_t left_thr;
  uint16_t right_thr;
  uint8_t buttons;
};


void setup() {
  Serial.begin(9600);
  Wire.begin(MASTER_ADDR);
}

Throttle_data td = {0};
int i=0;

void loop() {
  Serial.println("Requesting...");
  Wire.requestFrom(THROTTLE_ADDR, sizeof(Throttle_data));
  i=0;
  while(Wire.available()) {
    char c = Wire.read();
    ((char*)(&td))[i++] = c;
    Serial.print("read : ");
    Serial.println((int)c);
  }
  Serial.print("Buttons: ");
  Serial.println(td.buttons);
  delay(1000);
}

