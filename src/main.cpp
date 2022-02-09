#include <Arduino.h>

#include "MotorDriver.h"
#include "MotorDefines.h"


QuadEncoder motor_1_encoder(1, MOTOR_1_PIN_ENCODER, MOTOR_1_PIN_ENCODER, 0);


MotorDriver motor_1 = MotorDriver(MOTOR_1_PIN_1, MOTOR_1_PIN_2, MOTOR_1_PIN_PWM, MOTOR_1_PIN_ENCODER, motor_1_encoder);
//MotorDriver motor_2 = MotorDriver(MOTOR_2_PIN_1, MOTOR_2_PIN_2, MOTOR_2_PIN_PWM, MOTOR_2_PIN_ENCODER, motor_2_encoder_counter);
//MotorDriver motor_3 = MotorDriver(MOTOR_3_PIN_1, MOTOR_3_PIN_2, MOTOR_3_PIN_PWM, MOTOR_3_PIN_ENCODER, motor_3_encoder_counter);
//MotorDriver motor_4 = MotorDriver(MOTOR_4_PIN_1, MOTOR_4_PIN_2, MOTOR_4_PIN_PWM, MOTOR_4_PIN_ENCODER, motor_4_encoder_counter);

void setup() {
    
    motor_1_encoder.setInitConfig();
    motor_1_encoder.EncConfig.IndexTrigger = ENABLE;  //enable to  use index counter
    motor_1_encoder.EncConfig.INDEXTriggerMode = RISING_EDGE;
    motor_1_encoder.init();

    motor_1.initialize();

    motor_1.setDirection(true);


    for(uint8_t i = 0; i < 255; ++i) {
        motor_1.setPWM(i);
        Serial.print("1:"); Serial.print(motor_1.getSpeed_Hz());
        delay(100);
    }
    delay(2000);

    for(uint8_t i = 255; i > 1; --i) {
        motor_1.setPWM(i);        
        Serial.print("1:"); Serial.print(motor_1.getSpeed_Hz());
        delay(100);
    }

    motor_1.setPWM(0);
}

void loop() {
}