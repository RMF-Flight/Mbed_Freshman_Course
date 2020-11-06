/*
@file main.cpp
@author ishizeki
@brief
      TargetCPU               :STM32F303K8T6
      mbed libraly number     :172:65be27845400
      Revision of this file   :2020/11/7 -1
*/

#include <mbed.h>

//MPU6050センサのI2Cアドレスを定数として宣言しておく
//ADOピンをHIGHにするかGNDにするかでI2Cアドレスが変わる(すなわち、一つのI2Cラインで2つまで動かせる)

const int  MPU6050_ADDR = 0xD0;//MPU6050用(ADOピンをGNDに接続) 0xD0 = 0x68 << 1
//const int MPU6050_ADDR = 0xD1;//MPU6050用(ADOピンを3V3に接続) 0xD2 = 0x69 << 1

//I2C（センサとの通信）の初期化
I2C i2c(I2C_SDA,I2C_SCL);

//シリアル通信の定義(USB経由)
Serial serialUSB(PA_2,PA_15);

//レジスタを指定して1バイト書き込む関数
//dAddr:センサのI2Cアドレス
//rAddr:センサの指定したいレジスタのアドレス
//data:書き込みたいデータ(1Byte)
void writeOneByte(unsigned char dAddr,unsigned char rAddr,unsigned char data){
    //mbedのi2c.writeを使いやすいように配列の形で変数を定義する
    unsigned char buf[2];
    buf[0] = rAddr;//センサ内のレジスタの指定
    buf[1] = data;//設定値

    //書き込み(詳しくは公式HP参照)
    i2c.write(dAddr,(const char*)buf,2,false);
}

//レジスタを指定して1バイト読み込む関数
//dAddr:センサのI2Cアドレス
//rAddr:センサの指定したいレジスタのアドレス
unsigned char readOneByte(unsigned char dAddr,unsigned char rAddr){
    //mbedのi2c.writeを使いやすいように配列の形で変数を定義
    unsigned char buf[1];
    buf[0] = rAddr;//センサ内のレジスタの指定

    //書き込み
    i2c.write(dAddr,(const char*)buf,1,true);//レジスタ指定
    i2c.read(dAddr,(char*)buf,1,false);//データ読み込み
    
    //結果を返す
    return buf[0];
}



