#include "mbed.h"
#include "hcsr04.h"

Serial pc(USBTX, USBRX);    // PCとのUSB接続
DigitalOut myLED(LED1);     // デバッグ用のオンボードLED
HCSR04 usensor(D3, D6);     // (Trigger-Pin, Eho-Pin): Trigger-Pin は DigitalOut設定、Echo-Pin は InterruptIn設定可能なピン

unsigned int dist;  // 超音波センサの測定距離

int main() {
    // シリアル通信設定
    pc.baud(115200);
    pc.printf("Start Serial Communication.\r\n ");
    
    while (1) {
        // 超音波センサデータ取得とシリアル送信
        usensor.start();    // パルス幅 10[us] のトリガー信号を出力
        wait_ms(30);       // 測定距離と超音波の往復時間を考慮して決定: 30[ms] <-> MAX 約5mの測距範囲 (変更可)
        dist = usensor.get_dist_cm();       // 音速を仮定して計算 (気温等により修正するのもアリ) 
        pc.printf("%d [cm]\r\n", dist);    // シリアル送信
        wait_ms(100);
    }
}

