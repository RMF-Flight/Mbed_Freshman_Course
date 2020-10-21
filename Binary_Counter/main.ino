// 二進数カウンタ

// タクトスイッチの使い方：参考サイト
//　https://deviceplus.jp/hobby/arduino_f06/

const int LED0 = 2;
const int LED1 = 3;
const int LED2 = 4;
const int SWITCH = 10;

int val = 1, old_val = 1; // スイッチの電圧状態
int count = 0;   // カウンタ
bool led0, led1, led2; // LEDの点灯状態

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SWITCH, INPUT);
  
  Serial.begin(9600);
  
  led0 = 0;
  led1 = 0;
  led2 = 0;
}

void loop() {
  old_val = val;
  val = digitalRead(SWITCH);
  
  if ((old_val == LOW) && (val == HIGH)) {
    count ++;
    if (count >= 8) {
      count = 0; // カウントのリセット
    }
  }
  
  led0 = count & B00000001;
  led1 = (count >> 1) & B00000001;
  led2 = (count >> 2) & B00000001;
  
  digitalWrite(LED0, led0);
  digitalWrite(LED1, led1);
  digitalWrite(LED2, led2);
  
  Serial.println(count);
  
  delay(50); // バウンシング（チャタリング）対策: 10～50 msec の遅延
}
