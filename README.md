# ZiboRDM6300 Library

A lightweight and efficient Arduino library for interfacing with the RDM6300 RFID reader module. This library handles frame parsing, tag extraction, and checksum validation to quickly and reliably detect RFID tags.

## Installation

1. Download the library as a ZIP file from this repository.
2. Open the Arduino IDE.
3. Go to **Sketch** > **Include Library** > **Add .ZIP Library**.
4. Select the downloaded ZIP file.
5. The library will now appear under **ZiboRDM6300** in the Arduino Library Manager.

## Wiring

- **RDM6300 TX** → **Arduino RX Pin** (e.g., D6)
- **RDM6300 RX** → **Arduino TX Pin** (e.g., D8)
- **Power the RDM6300 with 5V**.
- **Connect GND properly**.

Note: The library uses SoftwareSerial, so you can define any digital pins for RX and TX.

## Example Usage

```cpp
#include <ZiboRDM6300.h>

// Initialize RFID reader: RX pin 6, TX pin 8
ZiboRDM6300 rfid(6, 8);

void setup() {
  Serial.begin(9600);
  rfid.begin(9600);
  Serial.println("ZiboRDM6300 RFID Reader Initialized");
}

void loop() {
  if (rfid.readTag()) {
    Serial.println("--------");
    Serial.print("Tag: ");
    Serial.println(rfid.getTag());
    Serial.print("Checksum: ");
    Serial.println(rfid.isChecksumValid() ? "OK" : "NOT OK");
    Serial.println("--------");
  }
}
```

🧑‍💻 Developer Info
Md Shaifulla Zibon
IoT Systems Designer | SMPS Engineer | Web Dashboard Integrator
🎓 B.Sc. in Electrical and Electronic Engineering
🏫 European University of Bangladesh
