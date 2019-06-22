/** Example for button(按钮实例)
* 功能 : 通过点击AST Kit上的按钮达到控制小灯开关的效果
* 管脚使用 : Arduino 中的 8,9,10 分别对应三个小灯, 4,11,12分别对应三个按钮
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/
#define LED1 8
#define LED2 9
#define LED3 10

#define KEY1 4
#define KEY2 11
#define KEY3 12

int KEY_NUM1 = 0;      //按键键值存放变量，不等于1说明有按键按下
int KEY_NUM2 = 0;     //按键键值存放变量，不等于1说明有按键按下
int KEY_NUM3= 0;      //按键键值存放变量，不等于1说明有按键按下

void setup()
{
  pinMode(LED1,OUTPUT);     //定义LED为输出引脚
  pinMode(KEY1,INPUT_PULLUP);   //定义KEY为带上拉输入引脚

  pinMode(LED2,OUTPUT);     //定义LED为输出引脚
  pinMode(KEY2,INPUT_PULLUP);   //定义KEY为带上拉输入引脚

  pinMode(LED3,OUTPUT);     //定义LED为输出引脚
  pinMode(KEY3,INPUT_PULLUP);   //定义KEY为带上拉输入引脚
}

void loop()
{
  ScanKey();        //按键扫描程序，当按键按下时候，该子程序会修改KEY_NUM的值
  if(KEY_NUM1 == 1)     //是否按键按下
  {   
    digitalWrite(LED1,!digitalRead(LED1));//LED的状态翻转
  }
  if(KEY_NUM2 == 1)     //是否按键按下
  {   
    digitalWrite(LED2,!digitalRead(LED2));//LED的状态翻转
  }
  if(KEY_NUM3 == 1)     //是否按键按下
  {   
    digitalWrite(LED3,!digitalRead(LED3));//LED的状态翻转
  }
}

void ScanKey()        //按键扫描程序
{
  KEY_NUM1 = 0;       //清空变量
  KEY_NUM2 = 0;       //清空变量
  KEY_NUM3 = 0;       //清空变量
  if(digitalRead(KEY1) == LOW)    //有按键按下
  {
    delay(20);        //延时去抖动
    if(digitalRead(KEY1) == LOW)    //有按键按下
    {
      KEY_NUM1 = 1;     //变量设置为1
      while(digitalRead(KEY1) == LOW);  //等待按键松手
    }
    }
    if(digitalRead(KEY2) == LOW)    //有按键按下
    {
      delay(20);        //延时去抖动
      if(digitalRead(KEY2) == LOW)    //有按键按下
    {
      KEY_NUM2 = 1;     //变量设置为1
      while(digitalRead(KEY2) == LOW);  //等待按键松手
    }
    }
    if(digitalRead(KEY3) == LOW)    //有按键按下
    {
      delay(20);        //延时去抖动
      if(digitalRead(KEY3) == LOW)    //有按键按下
    {
      KEY_NUM3 = 1;     //变量设置为1
      while(digitalRead(KEY3) == LOW);  //等待按键松手
    }
  }
}

