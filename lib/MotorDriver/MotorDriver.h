#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include <Arduino.h>
#include "QuadEncoder.h"

class MotorDriver {
    public:
        MotorDriver(uint8_t pin_1, uint8_t pin_2, uint8_t pwm_pin, uint8_t encoder_pin, QuadEncoder &quad_encoder);

        void initialize(void);

        void setPWM(uint8_t pwm_input);
        void setDirection(bool clockwise);
        void brake(void);
        float getSpeed_Hz(void);


    private:
        uint8_t _pin_1;
        uint8_t _pwm_pin;
        uint8_t _pin_2;
        QuadEncoder &_quad_encoder;
        uint32_t _previous_time;
        uint64_t _previous_encoder_counter;
};

#endif