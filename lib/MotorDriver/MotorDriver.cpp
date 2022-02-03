#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pin_1, uint8_t pin_2, uint8_t pwm_pin, uint8_t encoder_pin, volatile uint64_t &encoder_counter) :
    _pin_1(pin_1), _pwm_pin(pwm_pin), _pin_2(pin_2), _encoder_pin(encoder_pin), _encoder_counter(encoder_counter) {}


void MotorDriver::initialize(void) {
    pinMode(this->_pin_1, OUTPUT);
    pinMode(this->_pin_2, OUTPUT);
    pinMode(this->_pwm_pin, OUTPUT);
    pinMode(this->_encoder_pin, INPUT);

    analogWriteFrequency(this->_pwm_pin, 488);
}

void MotorDriver::setSpeed(uint8_t speed) {
    analogWrite(this->_pwm_pin, speed);
}

void MotorDriver::setDirection(bool clockwise) {
    if (!clockwise) {
        digitalWrite(this->_pin_1, LOW);
        digitalWrite(this->_pin_2, HIGH);
    } else {
        digitalWrite(this->_pin_1, HIGH);
        digitalWrite(this->_pin_2, LOW);
    }

}