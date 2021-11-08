#include <stdlib.h>
#include <stdio.h> 
#include <math.h>           //距離を求める際に逆三角関数を使うため必要
#include "mbed.h"
#include "BME280.h"
Serial pc(USBTX, USBRX, 115200);
BME280 sensor(D4, D5);

int main(){
    printf("\nSTM32 ADC internal channels reading example\n");
    while(1) {
        pc.printf("%2.2f degC, %04.2f hPa, %2.2f %%\r\n", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());        
        wait(1.0);
    }
}
