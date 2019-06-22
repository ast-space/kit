/** Example for relay(继电器控制实例)
* 功能 : 通过控制继电器打开或关闭继电器打开小灯
* 管脚使用 : Arduino 中的A3为继电器管脚
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(A3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(A3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
