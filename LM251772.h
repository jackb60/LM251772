#include "Arduino.h"
#include "Wire.h"

class LM251772 {
    public:
        LM251772(byte adc, TwoWire* wire = &Wire);
        void begin();
        void clearFaults();
        void setVoltage(float voltage);
        byte status();
        void output(bool on);
        float current();
    private:
        TwoWire* _Wire;
        byte _adr = 0x6A;
        byte _adc;
        void _writeReg(byte reg, byte data);
        byte _readReg(byte reg);
};