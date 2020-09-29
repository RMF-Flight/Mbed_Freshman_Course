// 二進数カウンタ

// 今回、タクトスイッチ用の入力ピンはプルアップ
// タクトスイッチの使い方：参考サイト
//　https://deviceplus.jp/hobby/arduino_f06/

#include "mbed.h"

int val = 1, old_val = 1;   // スイッチの電圧状態
int count = 0;          // カウンタ
bool led0_state, led1_state, led2_state;  // LEDの点灯状態

// シリアル通信用クラスの定義
// pcとの有線による通信を可能にする
Serial pc(PA_2, PA_15);   //tx, rx

int main() {
  // setup()関数の中身(1回だけ実行)
  
  // ピンの設定
  DigitalOut led0(D3);
  DigitalOut led1(D4);
  DigitalOut led2(D5);
  DigitalIn readSwitch(D6);
  
  pc.baud(9600);
  
  // LEDの点灯状態の初期化（全て消灯）
  led0_state = 0;
  led1_state = 0;
  led2_state = 0;
  
  // loop()関数の中身(無限ループ)
  while(1){
    old_val = val;
    val = readSwitch;   //スイッチのついたピンの読み取り結果を代入
    
    if ((old_val == 0) && (val == 1)) {
      count ++;
      if (count >= 8) {
        count = 0;    // カウントのリセット
      }
    }
    
    led0_state = count & 0b00000001;
    led1_state = (count >> 1) & 0b00000001;
    led2_state = (count >> 2) & 0b00000001;
    
    //ledの点灯状態に合わせて実際に点灯させる(mbedでは代入するように表す)
    led0 = led0_state;
    led1 = led1_state;
    led2 = led2_state;
    
    //コンソールに表示
    pc.printf("count:%d\n", count);
    
    //チャタリング対策: 10～50 msec の遅延
    wait_ms(50); 
  }
}
