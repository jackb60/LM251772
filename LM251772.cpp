#include "Arduino.h"
#include "LM251772.h"
#include "Wire.h"

LM251772::LM251772(byte adc, byte adr, TwoWire* wire) {
    _Wire = wire;
    _adc = adc;
    _adr = adr;
}

void LM251772::begin() {
    _Wire->begin();
}

void LM251772::_writeReg(byte reg, byte data) {
    _Wire->beginTransmission(_adr);
    _Wire->write(reg);
    _Wire->write(data);
    _Wire->endTransmission();
}

byte LM251772::_readReg(byte reg) {
    _Wire->beginTransmission(_adr);
    _Wire->write(reg);
    _Wire->endTransmission(false);
    _Wire->requestFrom(_adr, 1);
    return _Wire->read();
}

void LM251772::clearFaults() {
    _writeReg(0x03, 0x00);
}

void LM251772::setVoltage(float voltage) {
    unsigned int toSend = voltage / 0.02;
    _Wire->beginTransmission(_adr);
    _Wire->write(0x0C);
    _Wire->write((byte) toSend);
    _Wire->write((byte) (toSend >> 8));
    _Wire->endTransmission();
}

byte LM251772::status() {
    return _readReg(0x78);
}

void LM251772::output(bool on) {
    if (on) {
        _writeReg(0xD0, 0x23);
    } else {
        _writeReg(0xD0, 0x22);
    }
}

float LM251772::current() {
    return analogRead(_adc) * (3.3/1023) * 20.0;
}
