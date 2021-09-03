#include "mbed.h"

float val = 0 ;   // フォトリフレクタの電圧状態
// シリアル通信用クラスの定義
// pcとの有線による通信を可能にする
Serial pc(PA_2, PA_15);   //tx, rx

int main() {
  // setup()関数の中身(1回だけ実行)
  
  // ピンの設定
  AnalogIn readsensor(A3);
  
  pc.baud(9600);
  // loop()関数の中身(無限ループ)
  while(1){
    val = readsensor;   //スイッチのついたピンの読み取り結果を代入
       
    //コンソールに表示
    pc.printf("val:%f\n", val);
    
    //チャタリング対策: 10～50 msec の遅延
    wait_ms(50); 
  }
}
