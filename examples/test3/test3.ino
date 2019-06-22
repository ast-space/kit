* 管脚使用 : Arduino 中的5,6为RGB小灯管脚
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
* 通过遥控器第二排和第三排按键控制RGB小灯亮度
**/
#include <IRremote.h>
 
int RECV_PIN = 11;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 int blue=3;
int red=5;
int green=6;

 int b=0;
int r=0;
int g=0;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value); //串口显示开灯
 if(results.value==16720605)      //确认接收到的第一排按键1的编码，此码是预先读出来的按键编码。
  {
r=r+10;
  }
 
  if(results.value==16712445)
  {
    r=r-10;
    }
    if(results.value==16769055)
  {
     g=g-10;
    }
    else if(results.value==16754775)
  {
     g=g+10;
    }
    irrecv.resume(); // 接收下一个值
  }
  if((g>255))
  {g=255;}
  else if(g<0)
  {g=0;}
  if((r>255))
  {r=255;}
  else if(r<0)
  {r=0;}
   analogWrite(red,r);
    analogWrite(green,g);
}