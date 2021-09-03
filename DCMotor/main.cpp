// DC Motor control with PWM
#include "mbed.h"
#include "DCMotor.h"

DCMotor dcMotor1(D7, D9);

int main(){
    wait(5);
    while(1) {
        // 正転
        dcMotor1.forward(0.5);
        wait(3);
        dcMotor1.forward(1.0);
        wait(2);
        dcMotor1.forward(0.5);
        wait(3);
        // ブレーキ
        dcMotor1.brake();
        wait(3);
        // 反転
        dcMotor1.backward(0.5);
        wait(3);
        dcMotor1.backward(1.0);
        wait(2);
        dcMotor1.backward(0.5);
        wait(3);
        // 自然減速
        dcMotor1.stop();
        wait(3);
    }
}
