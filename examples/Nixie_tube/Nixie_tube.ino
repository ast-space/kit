/** Example for Nixie_tube (数码管实例)
* 功能 : 通过控制数码管实现数字显示
* 管脚使用 : 
* Nixie_tube a pin to pin D7
* Nixie_tube b pin to pin D6
* Nixie_tube c pin to pin D5
* Nixie_tube d pin to pin D4
* Nixie_tube e pin to pin D3
* Nixie_tube f pin to pin D2
* Nixie_tube g pin to pin D1
* Nixie_tube h pin to pin D0
* Nixie_tube w1 pin to pin A5
 * Nixie_tube w2 pin to pin A4
 * Nixie_tube w3 pin to pin A3
 * Nixie_tube w4 pin to pin A2
* 作者 : 陈小天
* 修改 :  XP
* 版本 :　V1.0
**/

int a=7;
int b=6;
int c=5;
int d=4;
int e=3;
int f=2;
int g=1;
int h=0;
int W4=A2;
int W3=A3;
int W2=A4;
int W1=A5;
long n=0;
int x=100;
int del=55;

void setup()
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  pinMode(W4,OUTPUT);
  pinMode(W3,OUTPUT);
  pinMode(W2,OUTPUT);
  pinMode(W1,OUTPUT);
}

void loop()
{
  clearLEDs();
  pickDigit(1);
  pickNumber(1);

  clearLEDs();
  pickDigit(2);
  pickNumber(2);

  clearLEDs();
  pickDigit(3);
  pickNumber(3);

  clearLEDs();
  pickDigit(4);
  pickNumber(4);
}

void pickDigit(int x)
{
  digitalWrite(W1,HIGH);
  digitalWrite(W2,HIGH);
  digitalWrite(W3,HIGH);
  digitalWrite(W4,HIGH);
  switch(x)
  {
    case 1:
      digitalWrite(W1,LOW);
      break;
    case 2:
      digitalWrite(W2,LOW);
      break;
    case 3:
      digitalWrite(W3,LOW);
      break;
    default:
      digitalWrite(W4,LOW);
      break;
  }
}
void pickNumber(int x)
{
  switch(x)
  {
    default:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}
void dispDec(int x)
{
  digitalWrite(h,HIGH);
}
void clearLEDs()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(h,LOW);
}
void zero()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}

void one()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void two()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void three()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void four()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void five()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void six()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void seven()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void eight()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void nine()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  
}
