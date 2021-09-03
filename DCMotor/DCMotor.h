#ifndef MBED_DCMOTOR_H
#define MBED_DCMOTOR_H

#include "mbed.h"

// モータードライバ: TB67H450FNG
// DCモーター定格電圧: 3V
// モーター電源電圧: 9V

#define MV 9.0      // MV: モーター用電源電圧
#define M_min 1.5   // M_min ~ M_max: モーター印加電圧範囲
#define M_max 3.0

class DCMotor {
public:
    DCMotor(PinName pin1, PinName pin2);
    void forward(float power);    // 正転 power: 0 ~ 1 (float)
    void backward(float power);   // 反転 power: 0 ~ 1 (float)
    void brake();   // ブレーキ
    void stop();    // 自然減速
    
private:
    PwmOut _IN1;
    PwmOut _IN2;
};

#endif
