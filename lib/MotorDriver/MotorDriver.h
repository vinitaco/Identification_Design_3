#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include <Arduino.h>

class MotorDriver {
    public:
        MotorDriver(uint8_t pin_1, uint8_t pin_2, uint8_t pwm_pin, uint8_t encoder_pin, volatile uint64_t &encoder_counter);

        void initialize(void);

        void setSpeed(uint8_t speed);
        void setDirection(bool clockwise);
        void brake(void);

    private:
        uint8_t _pin_1;
        uint8_t _pwm_pin;
        uint8_t _pin_2;
        uint8_t _encoder_pin;
        uint64_t _encoder_counter;
};

#endif