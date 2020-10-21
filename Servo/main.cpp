#include "mbed.h"
#include "Servo.h"

Servo myservo(D3);

int main() {
    while (1){
        // Servo::setAngle() の使用例
        myservo.setAngle(45);
        wait(0.5);
        myservo.setAngle(135);
        wait(0.5);
        myservo.setAngle(180);
        wait(0.5);
        myservo.setAngle(90);
        wait(2.0);
        myservo.setAngle(0);
        wait(0.5);
        
    }
}