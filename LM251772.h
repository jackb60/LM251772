#include "Arduino.h"
#include "Wire.h"

class LM251772 {
    public:
        LM251772(byte adc, byte adr, TwoWire* wire = &Wire);
        void begin();
        void clearFaults();
        void setVoltage(float voltage);
        byte status();
        void output(bool on);
        float current();
    private:
        TwoWire* _Wire;
        byte _adc;
        byte _adr;
        void _writeReg(byte reg, byte data);
        byte _readReg(byte reg);
};
