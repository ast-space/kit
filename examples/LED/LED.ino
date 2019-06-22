/** Example for LED(LED跑马灯实例)
* 功能 : 通过控制LED小灯开关实现跑马灯
* 管脚使用 : Arduino 中的 8,9,10号管脚对应三个小灯
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);   
  delay(200);              
  digitalWrite(8, LOW);    
  delay(200);              
  digitalWrite(9, HIGH);   
  delay(200);              
  digitalWrite(9, LOW);    
  delay(200); 
  digitalWrite(10, HIGH);   
  delay(200);              
  digitalWrite(10, LOW);    
  delay(200); 
}
