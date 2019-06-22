/** Example for photocell(光敏电阻实例)
* 功能 : 通过采集当前光照强度控制小灯开关,当光线过暗时打开小灯,当光线强时关闭小灯
* 管脚使用 : Arduino 中的 A2是光敏电阻管脚,A3为继电器管脚
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

int analog=0;
void setup() {
  Serial.begin(9600);
  pinMode(A3,OUTPUT);
}

void loop() {
  analog=analogRead(A2);
  Serial.println(analog);
  if(analog>500)
  {
    digitalWrite(A3,HIGH);
  }
  else
  {
    digitalWrite(A3,LOW);
  }
   delay(1000);
}
