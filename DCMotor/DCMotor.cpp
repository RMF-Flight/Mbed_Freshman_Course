#include "DCMotor.h"

DCMotor::DCMotor(PinName pin1, PinName pin2) : _IN1(pin1), _IN2(pin2) {
    _IN1.period(0.001); // 周期: 1ms (周波数: 1[kHz])
    _IN2.period(0.001); // 周期: 1ms
    _IN1.write(0);      // デューティー比を0で初期化
    _IN2.write(0);      // デューティー比を0で初期化
}

// 指定されたパワーで正転(IN1:+, IN2:-)
void DCMotor::forward(float power) {
    float duty = (M_min + (M_max - M_min) * power) / MV;    // duty: 0 ~ 1 (float)
    _IN1.write(duty);
    _IN2.write(0);
}

// 指定されたパワーで反転(IN1:-, IN2:+)
void DCMotor::backward(float power) {
    float duty = (M_min + (M_max - M_min) * power) / MV;    // duty: 0 ~ 1 (float)
    _IN1.write(0);
    _IN2.write(duty);
}

// ブレーキ(IN1:+, IN2:+)
void DCMotor::brake() {
    _IN1.write(1);
    _IN2.write(1);
}

// 自然減速(IN1:-, IN2:-)
void DCMotor::stop() {
    _IN1.write(0);
    _IN2.write(0);
}
