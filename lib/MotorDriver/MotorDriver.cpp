#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pin_1, uint8_t pin_2, uint8_t pwm_pin, uint8_t encoder_pin, volatile uint64_t &encoder_counter) :
    _pin_1(pin_1),
    _pwm_pin(pwm_pin),
    _pin_2(pin_2),
    _encoder_pin(encoder_pin),
    _encoder_counter(encoder_counter),
    _previous_time(micros()),
    _previous_encoder_counter(0)
    {}


void MotorDriver::initialize(void) {
    pinMode(this->_pin_1, OUTPUT);
    pinMode(this->_pin_2, OUTPUT);
    pinMode(this->_pwm_pin, OUTPUT);
    pinMode(this->_encoder_pin, INPUT);

    analogWriteFrequency(this->_pwm_pin, 488);
}

void MotorDriver::setPWM(uint8_t pwm_input) {
    analogWrite(this->_pwm_pin, pwm_input);
}

float MotorDriver::getSpeed_Hz(void) {
    uint32_t time = micros();
    uint32_t time_delta = time - this->_previous_time;
    uint32_t count_delta = this->_encoder_counter - this->_previous_encoder_counter;

    this->_previous_time = time;
    this->_previous_encoder_counter = this->_encoder_counter;

    return ((float)(1e6 * count_delta)) / ((float)time_delta) / 6533.0f;
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