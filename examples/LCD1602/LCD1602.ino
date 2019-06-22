/** Example for LCD1602(液晶显示器实例)
* 功能 : 通过驱动LCD1602实现字符显示
* 管脚使用 :
* LCD RS pin to pin A0
* LCD R/W pin to GND
* LCD ENA pin to pin A1
* LCD D4 pin to pin A2
* LCD D5 pin to pin A3
* LCD D6 pin to pin A4
* LCD D7 pin to pin A5 
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

#include <LiquidCrystal.h>// 引用LCD1602库

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("AST Space");
}

