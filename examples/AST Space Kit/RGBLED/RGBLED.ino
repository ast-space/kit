/** Example for RGBLED(红蓝绿三色控制实例)
* 功能 : 通过控制模拟信号输出实现三色小灯变化
* 管脚使用 : Arduino 中的3,5,6为RGB小灯管脚
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

int red=3;
int blue=5;
int green=6;
void setup() {
  
}

void loop() {
  analogWrite(red,150); //控制红色小灯亮度,取值范围为(0-255)
  analogWrite(blue,0);  //控制蓝色小灯亮度,取值范围为(0-255)
  analogWrite(green,0); //控制绿色小灯亮度,取值范围为(0-255)
}
