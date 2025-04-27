#include <ZiboRDM6300.h>

// Initialize the library with RX pin 6, TX pin 8
ZiboRDM6300 rfid(6, 8);

void setup() {
  Serial.begin(9600);
  rfid.begin(9600);
  Serial.println("ZiboRDM6300 RFID Reader Initialized");
}

void loop() {
  if (rfid.readTag()) {
    Serial.println("--------");
    Serial.print("Tag: "); Serial.println(rfid.getTag());
    Serial.print("Checksum: ");
    Serial.println(rfid.isChecksumValid() ? "OK" : "NOT OK");
    Serial.println("--------");
  }
}