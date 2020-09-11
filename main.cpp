// 二進数カウンタ

// タクトスイッチの使い方：参考サイト
//　https://deviceplus.jp/hobby/arduino_f06/

#include "mbed.h"

int val = 1, old_val = 1;   // スイッチの電圧状態
int count = 0;          // カウンタ
bool led0, led1, led2;  // LEDの点灯状態

DigitalOut led(LED1);

//シリアル通信用クラスの定義
//pcとの有線による通信を可能にする
Serial pc(PA_2,PA_15);  //tx, rx

int main()
{
  //setup()関数の中身(1回だけ実行)
  DigitalOut LED0(D3);
  DigitalOut LED1(D4);
  DigitalOut LED2(D5);
  DigitalIn Switch(D6);
  
  pc.baud(9600);
  
  led0 = 0;
  led1 = 0;
  led2 = 0;
  
  //loop()関数の中身(無限ループ)
  while(1){
    old_val = val;
    val = Switch;   //スイッチのついたピンの読み取り結果を代入
    
    if ((old_val == 0) && (val == 1)) {
      count ++;
      if (count >= 8) {
        count = 0;    // カウントのリセット
      }
    }
    
    led0 = count & 0b00000001;
    led1 = (count >> 1) & 0b00000001;
    led2 = (count >> 2) & 0b00000001;
    
    //ledの点灯状態に合わせて実際に点灯させる(mbedでは代入するように表す)
    LED0 = led0;
    LED1 = led1;
    LED2 = led2;
    
    //コンソールに表示
    pc.printf("count:%d\n", count);
    
    //チャタリング対策: 10～50 msec の遅延
    wait_ms(50); 
  }
}


