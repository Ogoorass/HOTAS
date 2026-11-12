#include <Wire.h>

const byte SLAVE_ADDR = 0x08;
const byte POT_PIN = A0;
const byte BUTTON_PIN = 8;
const byte LED_PIN = 9;

volatile int wartoscPot = 0;
volatile byte stanPrzycisku = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(zrealizujZadanie);
}

void loop() {
  wartoscPot = analogRead(POT_PIN);

  bool wcisniety = (digitalRead(BUTTON_PIN) == LOW);
  stanPrzycisku = wcisniety ? 1 : 0;
  digitalWrite(LED_PIN, wcisniety ? HIGH : LOW);

  delay(10);
}

void zrealizujZadanie() {
  byte dane[3];
  dane[0] = highByte(wartoscPot);  
  dane[1] = lowByte(wartoscPot);  
  dane[2] = stanPrzycisku;  
  Wire.write(dane, 3);
}