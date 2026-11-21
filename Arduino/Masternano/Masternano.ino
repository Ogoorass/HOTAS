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
    ((char*)(&td))[i++] = Wire.read();
  }
  Serial.print("Buttons: ");
  for(int i=0;i<8;i++) {
    Serial.print((bool)(td.buttons & (1 << i)));
  }
  Serial.print("\tL TH: ");
  Serial.print(td.left_thr);
  Serial.print("\tR TH: ");
  Serial.println(td.right_thr);
  delay(300);
}

