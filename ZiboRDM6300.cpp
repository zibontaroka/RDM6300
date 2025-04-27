#include <Arduino.h>
#include "ZiboRDM6300.h"

ZiboRDM6300::ZiboRDM6300(uint8_t rxPin, uint8_t txPin)
  : _ssrfid(rxPin, txPin), _idx(0), _tag(0), _checksumValid(false) {
}

void ZiboRDM6300::begin(long baudRate) {
  _ssrfid.begin(baudRate);
}

bool ZiboRDM6300::readTag() {
  if (_ssrfid.available()) {
    int val = _ssrfid.read();
    if (val == 2) _idx = 0; // Start of frame
    if (_idx < FRAME_SIZE) _buffer[_idx++] = val;
    if (val == 3 && _idx == FRAME_SIZE) {
      processTag();
      return true;
    }
  }
  return false;
}

long ZiboRDM6300::getTag() const {
  return _tag;
}

bool ZiboRDM6300::isChecksumValid() const {
  return _checksumValid;
}

void ZiboRDM6300::processTag() {
  _tag = hexToValue(_buffer + 3, 8);
  long checksum = 0;
  for (int i = 1; i <= 9; i += 2) {
    checksum ^= hexToValue(_buffer + i, 2);
  }
  _checksumValid = (checksum == hexToValue(_buffer + 11, 2));
}

long ZiboRDM6300::hexToValue(uint8_t *data, int len) {
  char str[len + 1];
  for (int i = 0; i < len; i++) str[i] = data[i];
  str[len] = '\0';
  return strtol(str, NULL, 16);
}