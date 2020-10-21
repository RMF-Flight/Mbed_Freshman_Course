#include "Servo.h"
#include "mbed.h"

Servo::Servo(PinName pin) : _servo(pin) {
    _servo.pulsewidth(0);     // パルス幅を0で初期化
}

// 指定された回転角の位置にサーボを動かす
void Servo::setAngle(int angle) {
    float pw = PW_MIN + angle / 180.0f * (PW_MAX - PW_MIN);
    _servo.pulsewidth(pw);
}

