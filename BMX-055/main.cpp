PwmOut MPwm(PA_11);

//USBシリアル出力
Serial USBSerial(PA_2,PA_15);
//タイマー設定
Ticker sensorTicker;

double delta_x, delta_y, now_x, now_y, r, sita;
float ax, ay, az, gx, gy, gz, mx, my, mz;
int i=0;
int heading_int;

    void Getdata() {      
      bmx.getMotion9(&ax,&ay,&az,
                     &gx,&gy,&gz,
                     &mx,&my,&mz);
      //USBSerial.printf("%d, %05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f\r\n",i, ax, ay, az, gx, gy, gz, mx, my, mz);
      USBSerial.printf("%d, %05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f,%05.3f\r\n",i, ax,ay,az,gx,gy,gz,mx, my,mz);
      i++;
      /*float heading = atan2(my, mx)*180/3.14;          //地磁気センサのx,y軸の値を使って、方位を計算(同時に角度の単位をラジアンからdegreeにも変換している)
            USBSerial.printf("heading : %f\n",heading);
            heading_int = (int)heading;
            //twe.printf("heading_int : %d\n",heading_int);
            heading_int = heading_int%360;                     //角度を0 <= heading < 360 にする
            heading_int = (-1)*heading_int + 90;
            if(heading_int >= 180){
                heading_int = heading_int - 360;
                }
            USBSerial.printf("heading_int : %d\n",heading_int);
        */
    }

int main() {
    USBSerial.baud(115200);
    bmx.init();
    
   // sensorTicker.attach(&Getdata, 0.1);
        
    while(1){
        Getdata();
        wait(0.1);
    }
        
        
    /*while(1){
        Getdata();
        wait(0.1);
        }
    */
        
    /*    
    while(1){
        delta_x = goal_x - now_x;
        delta_y = goal_y - now_y;
        
        r = sqrt(delta_x*delta_x+delta_y*delta_y);      //ゴールまでの距離を求める
        sita = atan2l(delta_y,delta_x)*180/3.14;        //現在地点からゴールまでの角度を求める
        float heading = atan2(my,mx)*180/3.14;
        heading = (int)heading%360;
        if(heading < 0){
            heading = heading*(-1);
            }
        double sita_new = heading - sita;            
        
        //sita_newを0にする動作
        MPwm = 0.7;
        In1 = 1;
        In2 = 0;
        wait(0.1);
        
        
        //rを0にするような動作
        wait(0.1);

        if(r<3.0){                                  //ゴールまでの距離が残り3mを切ったら、超音波センサを使って近く
            break;
            }
            
       
        }
        */
        

} 

