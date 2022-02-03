#include <Arduino.h>

#include "MotorDriver.h"
#include "MotorDefines.h"

volatile uint64_t motor_1_encoder_counter = 0;
volatile uint64_t motor_2_encoder_counter = 0;
volatile uint64_t motor_3_encoder_counter = 0;
volatile uint64_t motor_4_encoder_counter = 0;

MotorDriver motor_1 = MotorDriver(MOTOR_1_PIN_1, MOTOR_1_PIN_2, MOTOR_1_PIN_PWM, MOTOR_1_PIN_ENCODER, motor_1_encoder_counter);
MotorDriver motor_2 = MotorDriver(MOTOR_2_PIN_1, MOTOR_2_PIN_2, MOTOR_2_PIN_PWM, MOTOR_2_PIN_ENCODER, motor_2_encoder_counter);
MotorDriver motor_3 = MotorDriver(MOTOR_3_PIN_1, MOTOR_3_PIN_2, MOTOR_3_PIN_PWM, MOTOR_3_PIN_ENCODER, motor_3_encoder_counter);
MotorDriver motor_4 = MotorDriver(MOTOR_4_PIN_1, MOTOR_4_PIN_2, MOTOR_4_PIN_PWM, MOTOR_4_PIN_ENCODER, motor_4_encoder_counter);

void motor1ISR(void) {
    ++motor_1_encoder_counter;
}

void motor2ISR(void) {
    ++motor_2_encoder_counter;
}

void motor3ISR(void) {
    ++motor_3_encoder_counter;
}

void motor4ISR(void) {
    ++motor_4_encoder_counter;
}


void setup() {
    motor_1.initialize();
    motor_2.initialize();
    motor_3.initialize();
    motor_4.initialize();

    attachInterrupt(digitalPinToInterrupt(MOTOR_1_PIN_ENCODER), motor1ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(MOTOR_2_PIN_ENCODER), motor2ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(MOTOR_3_PIN_ENCODER), motor3ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(MOTOR_4_PIN_ENCODER), motor4ISR, RISING);


    //motor_1.setDirection(true);
    motor_2.setDirection(false);    
    //motor_3.setDirection(false);
    motor_4.setDirection(true);


    for(uint8_t i = 0; i < 255; ++i) {
        //motor_1.setSpeed(i);
        motor_2.setSpeed(i);
        //motor_3.setSpeed(i);
        motor_4.setSpeed(i);
        delay(10);
    }
    delay(2000);

    for(uint8_t i = 255; i > 1; --i) {
        //motor_1.setSpeed(i);
        motor_2.setSpeed(i);
        //motor_3.setSpeed(i);
        motor_4.setSpeed(i);
        delay(10);
    }

    motor_1.setSpeed(0);
    motor_2.setSpeed(0);
    motor_3.setSpeed(0);
    motor_4.setSpeed(0);


}

void loop() {
}