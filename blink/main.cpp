//Lチカ
#include "mbed.h"


DigitalOut led1(D3);

int main()
{
    while(1) {
        led1 = 1; //led1ピンをHIGHの状態(3.3V)にする
        wait(1.0);
        led1 = 0; //ledピンをLOWの状態(0V)にする
        wait(1.0);
    }
}
