#ifndef ZIBORDM6300_H
#define ZIBORDM6300_H

#include <SoftwareSerial.h>

class ZiboRDM6300 {
public:
  ZiboRDM6300(uint8_t rxPin, uint8_t txPin);
  void begin(long baudRate = 9600);
  bool readTag();
  long getTag() const;
  bool isChecksumValid() const;

private:
  static const int FRAME_SIZE = 14;
  SoftwareSerial _ssrfid;
  uint8_t _buffer[FRAME_SIZE];
  int _idx;
  long _tag;
  bool _checksumValid;

  void processTag();
  long hexToValue(uint8_t *data, int len);
};

#endif // ZIBORDM6300_H
