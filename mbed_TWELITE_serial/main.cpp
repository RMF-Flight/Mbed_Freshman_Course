#include "mbed.h"

Serial twe(PA_9, PA_10);
int i = 0;

//整数を1つ入力して、それをTWELITEで送る関数
void tweTransmit(int i){
        twe.printf("%d\n", i);
}
//test
int main(){
    twe.baud(115200);   //TWELITEとNUCLEOの通信のbaudrateを115200bpsに設定
    twe.printf("Start!\n\n");
    
    while(1){
        tweTransmit(i);
        i++;
        wait(1.0);
    }
    
}
