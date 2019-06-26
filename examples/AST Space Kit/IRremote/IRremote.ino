/** Example for IReomte(红外遥控实例)
* 功能 : 通过控制红外遥控器控制AST Kit中的小灯开关
* 管脚使用 : Arduino 中的 11 号角连接红外接收器
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

#include <IRremote.h> //引用红外库
 
int RECV_PIN = 11; //红外接收器数据管脚
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(A3,OUTPUT);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    if(results.value==16753245)      //确认接收到的第一排按键1的编码，此码是预先读出来的按键编码。
    {
      digitalWrite(A3,HIGH);                //点亮LED
      Serial.println("turn on LED"); //串口显示开灯
    }
    else if(results.value==16736925)   //确认接收到的第一排按键2的编码
    {
      digitalWrite(A3,LOW);            //熄灭LED
      Serial.println("turn off LED");    //串口显示关灯
    }
    irrecv.resume(); // 接收下一个值
  }
}
