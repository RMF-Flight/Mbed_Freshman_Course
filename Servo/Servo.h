#ifndef MBED_SERVO_H
#define MBED_SERVO_H

#include "mbed.h"
#define PWM_CYCLE 0.020     // PWM サイクル: 20ms
#define PW_MIN 0.0005       // 最小パルス幅: 0.5ms (0deg)
#define PW_MAX 0.0024       // 最小パルス幅: 2.4ms (180deg)

// 使用するサーボモーター: SG90 Micro Servo
// Operating Speed（動作速度）: 0.12s/60deg

class Servo {
public:
    Servo(PinName pin);
    void setAngle(int angle);

private:
    PwmOut _servo;
};

#endif